/* I made a swift file that check if a given number is a Happy Number.  
 A happy number is a number which eventually reaches 1 when replaced by the sum of the square of each digit. 
 Exemple: 13 -> 1^2 + 3^2 = 10
          10 -> 1^2 + 0^2 = 1 --> Happy number 
          
 Another Exemple: 4 -> 4^2 = 16
                  16 -> 1^2 + 6^2 = 37
                  37 -> 3^2 + 7^2 = 58
                  58 -> 5^2 + 8^2 = 89
                  89 -> 8^2 + 9^2 = 145
                  145 -> 1^2 + 4^2 + 5^2 = 42
                  42 -> 4^2 + 2^2 = 20
                  20 -> 2^2 + 0^2 = 4 --> Not a Happy number           
*/


import Foundation

var n = Int(readLine()!)!

func checkHappyNumber(_ number: Int, _ col: inout Set<Int>) -> Int {
    var result = 0
    var copy = number /* I created this variable "copy" because "number" is constant */
    
    col.insert(s)

    while copy != 0 {
        result += (copy % 10) * (copy % 10)
        copy /= 10
    }
    return (result)
}

var s = Set<Int>() /* I used this set to make sure that the numbers are unique and not repeated*/

var counter = 0

while n != 1 && !s.contains(n) {
    n = checkHappyNumber(n, &s)
    print("\(n) ", terminator: "")
    counter += 1
}

if n == 1 {
    print()
    print("I'm HAPPY")
} else {
    print()
    print("I'm SAD")
}


