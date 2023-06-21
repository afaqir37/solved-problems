import Foundation
/* given an integer, calculate this sum : 2^0 + 2^1 ... + 2^(n-1) using bitwise operations*/


var n = Int(readLine()!)!
var copy = n
var res = 0

// First method: 

while n > 0 {
    res <<= 1
    res = res | 1
    n -= 1
}

//Second method

var result = (1 << copy) - 1

print(res, result)