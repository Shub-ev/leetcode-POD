// Problem: 1344. Angle Between Hands of Clock
// Given two numbers, hour and minutes, return the smaller angle (in degrees)
// formed between the hour and the minute hand.
// Answers within 10-5 of the actual value will be accepted as correct.

// my approach:
// 1. The minute hand moves 6 degrees per minute (360 degrees / 60 minutes).
// 2. The hour hand moves 30 degrees per hour (360 degrees / 12 hours) and 0.5 degrees per minute (30 degrees / 60 minutes).


class Solution {
public:
    double angleClock(int hr, int min) {
        if(hr == 12) hr = 0;

        float min_angle_clk = min * 6;
        float hr_angle_clk = (30 * hr) + (0.5 * min);

        float gap = 0;
        if(min_angle_clk > hr_angle_clk) { 
            gap = min_angle_clk - hr_angle_clk;
        } else {
            gap = hr_angle_clk - min_angle_clk;
        }

        return gap > (360 - gap) ? (360 - gap) : gap; 
    }
};