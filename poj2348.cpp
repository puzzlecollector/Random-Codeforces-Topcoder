/*
Given a,b, let us assume that a < b (if not we can swap a and b in order to satisfy this constraint). 
First of all, note that if a = b or if b is some multiple of a, then the first player will trivially win.  
Excluding the trivial cases, note that we have 2 cases. 
1) b-a < a
2) b-a > a
In case 1), we have no choice but to subtract a from b (in order to satisfy the constraint that numbers should not become non-negative), 
but for 2), we can subtract either a or some positive multiple of a such that b is non-negative.Let us introduce the notion of 
winning and losing turns. Consider a = 3, b = 5. Then we have (3,5)->(3,2)->(1,2) and the game ends because 2-1*2 = 0. This suggests 
that (3,5) is a winning turn, (3,2) is a losing turn and (1,2) is a winning turn. So it's easy to see that winning and 
losing turns alternate. We can actually prove that case 2) is always a winning turn, so either of the player who reaches case 2)
first is guaranteed to win (under the assumptions that they are playing optimally). Suppose there is some x such that b-ax < a. 
Let's say then we subtract a(x-1) from b. If the turn after we subtract a(x-1) is a losing turn, then we are at a winning turn 
now, so we win the game.However, if the turn after we subtract a(x-1) is a winning turn, then we subtract ax instead of a(x-1)
to change the next turn to a losing turn. As an example, consider a = 4, b = 19. Then x = 4, and if we subtract 4*3 = 12 from 19, 
we get (4,19)->(4,7)->(4,3)->(1,3) and the game ends, so we have a lose,win,lose,win turn. Instead of subtracting 4*3, let us 
subtract 4*4 = 16, then we have (4,19)->(4,3)->(1,3), so we have a win,lose,win turn and we can win the game. So one that reaches 
case 2) first can always win. 

Below is a simple C++ implementation of the above algorithm. Basically the same logic is applied to my JavaScript code to verify
who the winner is. 
*/

#include <iostream> 
#include <algorithm> 
using namespace std; 
int main(){
  int a,b; 
  cin >> a >> b; 
  bool firstWins = true;  
  for (;;){
    if (a > b) swap(a,b);  
    if (b%a == 0) break; 
    if (b-a > a) break; 
    b -= a; 
    firstWins = !firstWins;  
   } 
   if (firstWins) cout << "Computer wins" << endl;  
   else cout << "Human wins" << endl; 
   return 0; 
}
    
