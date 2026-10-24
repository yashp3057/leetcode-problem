class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {

        string start = max(arriveAlice, arriveBob);
        string end = min(leaveAlice, leaveBob);

        if (start > end) {
            return 0;
        }

        int monthDays[] = {31, 28, 31, 30, 31, 30,
                           31, 31, 30, 31, 30, 31};

        int sm = stoi(start.substr(0, 2));
        int sd = stoi(start.substr(3, 2));
        int em = stoi(end.substr(0, 2));
        int ed = stoi(end.substr(3, 2));

        int startDay = sd;
        int endDay = ed;

        for (int i = 0; i < sm - 1; i++) {
            startDay += monthDays[i];
        }

        for (int i = 0; i < em - 1; i++) {
            endDay += monthDays[i];
        }

        return endDay - startDay + 1;
    }
};