Initial code, idea is to simulate the time keep tracking of the current time, on next iteration 
if an event arrive such that we have to wait, we have to consider extra time and update time elapsed.

double time_elapsed = 0, extra_time = 0, avg=0;
        for(auto i: customers)
        {
            avg +=i[1];
            if(i[0] >= time_elapsed)
            {
                time_elapsed = i[0] + i[1];
            }
            else
            {
                extra_time += (time_elapsed - i[0]);
                time_elapsed += i[1];
            }
        }
        return ((avg+extra_time)/customers.size());


cur means the current time.
for each custom arriving at t with his order needing d,
we start preparing his order at max(cur, t),
we finish his order at max(cur, t) + d,
and he waits for max(cur, t) + d - t,

We need to sum up the waiting time,
and also update the cur time after sever each custom.

     double wait = 0, cur = 0;
        for (auto& a: A) {
            cur = max(cur, 1.0 * a[0]) + a[1];
            wait += cur - a[0];
        }
        return 1.0 * wait / A.size();
