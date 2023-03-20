-- 这个是lua的注释
-- 运行环境在浏览器的一个网址里面,luatos

--[[这是一个多行注释
这里是第二行
这里是第三行
]]
-- 变量
a = 2
local b = 3

-- nil
c = nil

-- 多变量赋值
aone, bone, cone = 1, 2
print(aone,bone,cone)

-- 数值型
num1 = 0
num2 = 2.9
num3 = 0X11
num4 = 2e10

-- 算术运算符
-- lua支持^这个乘幂符号
-- 其他的和c语言一样

--字符串变量
--lua中有三种表示字符串变量的方式
--" ", ' ', [[ ]]

-- 转义字符
print("'")
print('"')
print("'\"\[\[]]\r")

-- 字符串拼接
str1 = "100"
str2 = "200"
print(str1 .. str2)
str3 = "3000"
print(str1 .. str3 .. str2)
str4 = "world"
print("hello," .. str4)

-- number转string
num = 100
str = "dollar"
all = tostring(n) .. str
print(all)
-- display-->  100dollar

-- string转numer
num4 = 100
str4 = "100"
resu = num4 + tonumber(str4)
print(resu)

--


--


