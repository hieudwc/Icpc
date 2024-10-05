# Đọc đầu vào
N = int(input())  # độ dài dãy ký tự
s = input()       # dãy ký tự gồm + và -
Q = int(input())  # số truy vấn

# Tính tổng giá trị dãy
sum_total = 0
for i in range(N):
    if s[i] == '+':
        sum_total += 1
    else:
        sum_total -= 1

# Xử lý các truy vấn
for _ in range(Q):
    a, b = map(int, input().split())
    
    # Tính tổng khi a đặt cho các vị trí dấu + và b cho các vị trí dấu -
    target_sum = a * s.count('+') + b * s.count('-')
    
    # Kiểm tra nếu tổng có thể đạt được bằng 0
    if sum_total == target_sum:
        print("YES")
    else:
        print("NO")
