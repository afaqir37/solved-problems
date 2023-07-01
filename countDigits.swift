import Foundation

// given a string, calculate the numnber of digits it contains, without counting those inside the /*...*/ 
// 123 world -> 3
// 123 /* 456 */ world -> 3
// 123 /* 456 /* 789 */ */ world -> 3
// "123 /* 2/3 */world" -> 3

func countDigits(_ str: String) -> Int {
    let arr = Array(str) 
    var count = 0
    var lock = 0
    var countLock = 0
    for i in 0..<arr.count - 1 {
        if arr[i] == "/" && arr[i + 1] == "*" {
            lock += 1
        } else if arr[i] == "*" && arr[i + 1] == "/" && lock != 0 {
            lock -= 1
            count -= countLock
            countLock = 0
        } else if lock == 0 && arr[i].isNumber {
            count += 1
        } else if lock != 0 && arr[i].isNumber {
            countLock += 1
            count += 1
        }
    }
    if arr[arr.count - 1].isNumber {
        count += 1
    }

    return count

}

//print(countDigits("/*/*9/**/"))
//print(countDigits("123 world"))
//print(countDigits("123 /* 456 */ world"))





