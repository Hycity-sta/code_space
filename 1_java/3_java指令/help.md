# java的命令行指令
自己摸索了一下, 大概知道怎么编译和运行了.

## 文件结构
文件结构大概如下:
src :用于存放代码
bin :用于存放编译后的.class文件

在src中,如果存在包结构,就要安装包结构来划分文件树.
例如: com.my 包, 就要在src\com\my 目录下. 这里\和/都是可以的, 不过由于在win下,使用\在命令行中比较好.
但是在java文件里面,对路径需要\\来表示.

## 编译
对于编译的参数,需要做一些说明.
1. javac
这个命令用来编译.java文件
例如: javac my.java

2. javac -d <路径>
这个-d参数用来指定编译后的文件的输出路径, 例如,我想让他输出到bin文件下.
javac -d bin my.java
就会在bin(或者说是.\bin)目录下输出编译后的文件.

如果my.java声明了自己属于哪一个包,例如com.example包, 那么在输出的时候,
会输出到bin\com\example路径下.

3. javac -cp <路径>
这个-cp参数用来指定搜索的类文件路径. 用来处理import的问题.
主要是import自己创建的类.
例如, 写了一个Person.java文件,它属于com.one包下
又写了一个Main.java文件,它属于com.two包下,并且,他import了com.one.Person包.
那么编译指令如下:
javac -d src\com\one\Person.java
javac -cp bin -d bin src\com\two\Main.java

第一行指定了Penson.java文件编译后的输出路径
第二行先指定了java要搜索的类路径在bin下, 在java编译Main.java文件的时候, 会在bin目录下的文件树进行查找.
也正因此,被依赖的类需要事先编译,不然需要这个类的其他类就不能被编译了.
之后,Main文件也被编译输出到了bin文件下,因为Main文件声明了一个包,所以它会自动创建一个com\two文件夹,在这个文件夹下存放Main.class文件

## 运行
编译完成之后,就是运行了.
新版的java支持直接用`java *.java`文件来进行即时编译.
但是还是预先编译成字节码文件.class, 然后运行.class文件比较好. 因为旧版是这样的.

在上面的例子中, 编译了Main和Person两个类, 分别产出了Person.class和Main.class两个类文件出来.
前提是,Person和Main的代码里面只有Person和Main这两个类.
要运行Main.class,要:
javac -cp bin com.two.Main
注意了, 这里很不一样.
-cp指定了java要搜索的类路径, 当运行的.class文件有依赖的类的时候,就会在-cp指定的路径下进行查询.
这里的-cp指定了bin目录.
而后的com.two.Main就是执行在bin\com\two\下的Main.class文件

这个有点类似于java中的import导入格式, 由.来分隔, 最后的字符串就是目标的类.
因为指定了-cp, 所以java在接受了com.two.Main这个指令后, 会去找哪里有com.two这个地方, 所以就会进入到bin目录下.
也因此找到了com\two 对应了com.two
而后寻找Main这个.class文件, 注意,这里Main后不用加.class的,因为在写java代码的时候,import 一个类的时候也没有加入.class

于是就运行了.

## 总结
1. 因为是初次接触,所以只用会java和javac这两个命令就好了. 同时,知道-cp和-d这两个参数也够用了.
2. 在运行的时候, 一定要先指定-cp.
3. 在编译的时候,要先把被依赖的类给先编译了.
4. 在运行的时候, 填的不是com\two这种路径了, 而是与代码中import格式那样的 com.two.Main 这个是java的规范
5. 虽然第四点有点难接受,因为目标文件是在路径下的,但是却要写成a.b.c的形式,这也是java本身的运行逻辑导致的吧. 符合语法,却又有别于一般的习惯.
6. 记于2023年5月19日晚
7. 嫌麻烦的话,写一个脚本来自动编译比较好.
8. 如果有需求的话才去接受其他的参数了.说不定也有调试器什么的...

