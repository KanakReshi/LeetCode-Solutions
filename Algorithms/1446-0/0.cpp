class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hour_angle = 30*(hour%12) + 0.5*minutes;
        double min_angle = minutes*6;
        return min(abs(hour_angle-min_angle) ,(360-abs(hour_angle-min_angle)));
    }
};