// Problem Link : https://leetcode.com/problems/design-event-manager/

class EventManager {
public:
    unordered_map<int, int> mp;
    set<pair<int, int>> st;
    EventManager(vector<vector<int>>& events) {
        for (auto& it : events) {
            int id = it[0];
            int pr = it[1];
            mp[id] = pr;
            st.insert({-pr, id});
        }
    }

    void updatePriority(int eventId, int newPriority) {

        int old = mp[eventId];
        st.erase({-old, eventId});
        mp[eventId] = newPriority;
        st.insert({-newPriority, eventId});
    }

    int pollHighest() {
        if (st.empty())
            return -1;
        auto it = st.begin();
        auto [p, id] = *it;
        st.erase(it);
        mp.erase(id);
        return id;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */
