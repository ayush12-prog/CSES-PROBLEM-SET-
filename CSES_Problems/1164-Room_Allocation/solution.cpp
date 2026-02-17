// CSES Problem 1164: Room Allocation
// Link: https://cses.fi/problemset/task/1164/
// Description: There is a large hotel, and n customers will arrive soon. Each customer wants to...

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct GuestRecord {
    int check_in;
    int check_out;
    int index_id;
};

bool arrange_by_arrival(const GuestRecord& first_guest, const GuestRecord& second_guest) {
    if (first_guest.check_in == second_guest.check_in) {
        return first_guest.check_out < second_guest.check_out;
    }
    return first_guest.check_in < second_guest.check_in;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int client_count;
    if (cin >> client_count) {
        vector<GuestRecord> ledger(client_count);
        for (int i = 0; i < client_count; ++i) {
            cin >> ledger[i].check_in >> ledger[i].check_out;
            ledger[i].index_id = i;
        }

        sort(ledger.begin(), ledger.end(), arrange_by_arrival);

        vector<int> room_assignments(client_count);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> active_occupancies;

        int total_rooms_utilized = 0;

        for (int i = 0; i < client_count; ++i) {
            if (active_occupancies.empty() || active_occupancies.top().first >= ledger[i].check_in) {
                total_rooms_utilized++;
                room_assignments[ledger[i].index_id] = total_rooms_utilized;
                active_occupancies.push({ledger[i].check_out, total_rooms_utilized});
            } else {
                int available_room = active_occupancies.top().second;
                active_occupancies.pop();
                room_assignments[ledger[i].index_id] = available_room;
                active_occupancies.push({ledger[i].check_out, available_room});
            }
        }

        cout << total_rooms_utilized << "\n";
        for (int i = 0; i < client_count; ++i) {
            cout << room_assignments[i] << (i == client_count - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}
