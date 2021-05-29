import re

def isPalindrome(str):
    str = str.lower()
    # 소문자처리

    str = re.sub('[^a-z0-9]', '', str)
    # re.sub('pattern', '바꿀 문자열', '적용할 문자열')
    # 특수문자와 숫자 제거

    if str == str[::-1]:
        print("is Palindrome")
    else:
        print("is not Palindrome")
        
def reverseString(str):
    str.reverse()
    #reverse function use
    print(str)

def sortCmpFunc(x):
    return x.split()[0], x.split()[1]
        
data = ['1 A', '1 B', '6 A', '2 D', '4 B']

data.sort(key=sortCmpFunc)
print(data)
