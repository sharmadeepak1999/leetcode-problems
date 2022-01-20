class Solution {
public:
    double angleClock(int hour, int minutes) {
        double angleHour, angleMin;
        hour = hour == 12 ? 0 : hour;
        angleMin = minutes * 6;
        angleHour = hour * 5 * 6 + ((double) minutes / 60) * 5 * 6;
        double diff = abs(angleHour - angleMin);
        return min(diff, 360 - diff);
    }
};