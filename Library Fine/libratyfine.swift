import Foundation

/*
 * Complete the 'libraryFine' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER d1
 *  2. INTEGER m1
 *  3. INTEGER y1
 *  4. INTEGER d2
 *  5. INTEGER m2
 *  6. INTEGER y2
 */

func libraryFine(d1: Int, m1: Int, y1: Int, d2: Int, m2: Int, y2: Int) -> Int {
    /*if (y1 < y2) {
        return 0;
    } else if(y1 == y2) {
        if(m1 < m2) {
            return 0;
        } else if(m1 == m2) {
            if(d1 <= d2) {
                return 0;
            }else {
                return (d1 - d2) * 15;
            }
        } else {
            return (m1 - m2) * 500;
        }
    }

    return 10000;*/
    
    if(y1 > y2) {
        return 10000;
    } else if(y1 == y2) {
        if(m1 > m2) {
            return (m1 - m2) * 500;
        } else if (m1 == m2) {
            if (d1 > d2) {
                return (d1 - d2) * 15;
            }
        }
    }
    
    return 0;
}

let stdout = ProcessInfo.processInfo.environment["OUTPUT_PATH"]!
FileManager.default.createFile(atPath: stdout, contents: nil, attributes: nil)
let fileHandle = FileHandle(forWritingAtPath: stdout)!

guard let firstMultipleInputTemp = readLine()?.replacingOccurrences(of: "\\s+$", with: "", options: .regularExpression) else { fatalError("Bad input") }
let firstMultipleInput = firstMultipleInputTemp.split(separator: " ").map{ String($0) }

guard let d1 = Int(firstMultipleInput[0])
else { fatalError("Bad input") }

guard let m1 = Int(firstMultipleInput[1])
else { fatalError("Bad input") }

guard let y1 = Int(firstMultipleInput[2])
else { fatalError("Bad input") }

guard let secondMultipleInputTemp = readLine()?.replacingOccurrences(of: "\\s+$", with: "", options: .regularExpression) else { fatalError("Bad input") }
let secondMultipleInput = secondMultipleInputTemp.split(separator: " ").map{ String($0) }

guard let d2 = Int(secondMultipleInput[0])
else { fatalError("Bad input") }

guard let m2 = Int(secondMultipleInput[1])
else { fatalError("Bad input") }

guard let y2 = Int(secondMultipleInput[2])
else { fatalError("Bad input") }

let result = libraryFine(d1: d1, m1: m1, y1: y1, d2: d2, m2: m2, y2: y2)

fileHandle.write(String(result).data(using: .utf8)!)
fileHandle.write("\n".data(using: .utf8)!)

