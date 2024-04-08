
Since students are moving in a ciruclar fashion order, we can say this statement 
In circular fashion order, in worst case, every student will be aware what is at the top of the stack.
Hence, we only care, if any student whose preference is equal to the current top of the stack sandwich is interested to eat that.
further, we dont even want to know what the index of the student, all we care is, is someone going to eat that damn sandwich or not
if not, someone is going to die hungry.
So think about it, if students who have preference all as zeros see the top of the stack as 1.
or if students who have preference all as ones , see the top of the stack as 0.


    int ones =0;
        int zeros=0;
        for(auto i: students)
            if(i==1)
                ones++;
            else if(i==0)
                zeros++;
        for(auto sandwich: sandwiches)
            if(sandwich ==0)
                if(zeros == 0)
                    return ones;
                else
                    zeros--;
            else
                if(ones == 0)
                    return zeros;
                else
                    ones--;
        return 0;
