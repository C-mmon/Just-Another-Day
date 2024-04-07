This problem cannot be done with your normal stack push pop.
You will figure out 20-30 test case will fail.

Now there is cmin and cmax approach,

There are two conditions in which the string is unbalanced
1. We encounter too many ')'
2. In the end, we still have some '(' which didn't find their matching ')'

cmax takes care of condition 1
cmax represents the number of ')' we MIGHT encounter. For cmax, we treat '*' as '('
So at any point of time, if cmax becomes negative, that means, with all the '(' and '*' we have encountered, there are more ')'. 
So return false
Note that we only worry about extra ')' 

cmin takes care of condition 2
cmin represents the number of ')' we MUST encounter. So the job of cmin is to get to 0 as quickly as possible
For cmin, we will always assume that '*' is a ')'. So whenever we encounter ')' or '*', we reduce cmin.
But, cmin can not go below 0. If this happens, we can assume few of the '*'s as empty.

Consider 
Example: "( ) * * "
cmax = 1 0 1 2
cmin = 1 0 0 0 -> We don't want the last two to become 1 0 -1 -2

We can see that the cmin values would become -1 and -2 for the last two "". 
However this would mean we would be adding additional ")", which makes the sequence "()))". This is not a right sequence. 
Therefore, we must keep them as empty strings. 
Hence we do a max with 0, which implies that if we have additional "", we don't take them as ")", instead we treat them as empty strings.

Also Don't worry about a condition like ()))) because we have cmax which takes care of this.
We only worry about extra '('
So at the end, if cmin is still > 0, this means, with all the '*' and ')' we encountered, there are more '(' present in the string
So return false

2024-04-07-18-46-55.png

Final code
          int cmin = 0, cmax = 0; // open parentheses count in range [cmin, cmax]
        for (auto  c : s.toCharArray()) {
            if (c == '(') {
                cmax++;
                cmin++;
            } else if (c == ')') {
                cmax--;
                cmin--;
            } else if (c == '*') {
                cmax++; // if `*` become `(` then openCount++
                cmin--; // if `*` become `)` then openCount--
                // if `*` become `` then nothing happens
                // So openCount will be in new range [cmin-1, cmax+1]
            }
            if (cmax < 0) return false; // Currently, don't have enough open parentheses to match close parentheses-> Invalid
                                        // For example: ())(
            cmin = Math.max(cmin, 0);   // It's invalid if open parentheses count < 0 that's why cmin can't be negative
        }
        return cmin == 0; // Return true if can found `openCount == 0` in range [cmin, cmax]
    }