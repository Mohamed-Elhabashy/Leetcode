class Solution {
public:

    struct state {
        long long score = 0;
        array<int, 4> ids{};
        int cnt = 0;
    };

    int n;

    vector<array<int, 4>> v;
    vector<int> nxt;

    bool vis[50005][5];
    state dp[50005][5];


    bool lexSmaller(const state& a, const state& b) {

        int sz = min(a.cnt, b.cnt);

        for(int i = 0; i < sz; i++) {

            if(a.ids[i] != b.ids[i])
                return a.ids[i] < b.ids[i];
        }

        return a.cnt < b.cnt;
    }


    state bestStep(const state& a, const state& b) {

        if(a.score > b.score)
            return a;

        if(b.score > a.score)
            return b;

        if(lexSmaller(a, b))
            return a;

        return b;
    }


    void addId(state& s, int id) {

        int pos = s.cnt;

        // insert id while keeping ids sorted
        while(pos > 0 && s.ids[pos - 1] > id) {

            s.ids[pos] = s.ids[pos - 1];

            pos--;
        }

        s.ids[pos] = id;

        s.cnt++;
    }


    state solve(int i, int rem) {

        if(i == n || rem == 0)
            return {};

        if(vis[i][rem])
            return dp[i][rem];

        vis[i][rem] = true;


        // skip
        state skip = solve(i + 1, rem);


        // take
        state take = solve(nxt[i], rem - 1);

        take.score += v[i][2];

        addId(take, v[i][3]);


        return dp[i][rem] = bestStep(skip, take);
    }


    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        n = intervals.size();

        nxt.resize(n);

        for(int i = 0; i < n; i++) {

            v.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }


        sort(v.begin(), v.end());


        // calculate next interval once
        for(int i = 0; i < n; i++) {

            int l = i + 1;
            int r = n;

            while(l < r) {

                int mid = (l + r) / 2;

                if(v[mid][0] > v[i][1])
                    r = mid;
                else
                    l = mid + 1;
            }

            nxt[i] = l;
        }


        state ans = solve(0, 4);


        vector<int> result;

        for(int i = 0; i < ans.cnt; i++)
            result.push_back(ans.ids[i]);

        return result;
    }
};