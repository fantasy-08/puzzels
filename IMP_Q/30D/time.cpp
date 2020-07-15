class Solution {
public:
    double angleClock(int hour, int minutes) {
        double angle_hr=30.0*hour+(0.5*minutes);
        double angle_min=6.0*minutes;
        double ans= fabs(angle_hr-angle_min);
        return min(ans,(360.0-ans));
    }
};
