
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>> p;
        for(int i=0; i<n; i++)
            p.push_back(make_pair(end[i], start[i]));
        sort(p.begin(), p.end());
        int ans=1, limit=p[0].first;
        for(int i=1; i<n; i++){
            if(p[i].second>limit){
                limit = p[i].first;
                ans++;
            }
        }
        return ans;
    }