

# 天火脚本FireML的设计动机 #
  1. 最常用的功能，如切换背景、显示立绘、显示对白，脚本要简洁，尽量提高书写速度。
  1. 复杂而不太常用的功能，如选择框、动画、特效等，脚本要易学，写好的脚本要易读。
  1. 脚本的语法标记要体现“语义”以更好地与剧情文字融合。或者说，脚本看起来要像剧本儿不是像程序。
  1. 能够实现智能化的编辑，包括代码提示、自动完成、编辑时语法检查等。

# 几个例子 #
## 一个反例 ##
事实上，天火引擎的有一个半成品的前身，它被我坑掉的原因就是丑陋的脚本设计，因为这个脚本长得太像编程语言了：<br />
**这是反例！！！**
```

Text.ShowSpeech("英", "那么，就只好这样了……！！",
     "test2", "e_in_awr.png");

SelectDialog.New("xuanzezhi");
SelectDialog.AddItem("淘汰伊俄",1);
SelectDialog.AddItem("可怜伊俄",0);
SelectDialog.Show();


if (xuanzezhi == 1)
{
    Charactor.Show("test2", "in_fa06nm.png", 30, 0);
    Text.ShowSpeech("英", "伊俄，对不起，请把潘叫过来……",
        "test2", "e_in_awr.png");
    Charactor.Show("test2", "io_fa01wr.png", 30, 0);
    Text.ShowSpeech("伊俄", "对，对不起……呜呜……不要淘汰我……",
        "test2", "e_io_asm.png");
}
else
{
    Charactor.Show("test2", "in_fa06nm.png", 30, 0);
    Text.ShowSpeech("英", "伊俄，好吧，再给你一次机会！一定要加油啊~",
        "test2", "e_in_awr.png");
    Charactor.Show("test2", "io_fa01wr.png", 30, 0);
    Text.ShowSpeech("“俄底浦斯”", "为什么？！",
        "test2", "e_io_asm.png");
}

```
而一个AVG游戏引擎的脚本，要描述的是一个丰富有趣的剧情，而不是指令集。

## 最简单又最复杂的FireML ##
最简单，因为下面的代码只用到了最基本的FireML功能；最复杂，因为下面的代码没有利用FireML的高级功能来简化代码编写。
```
  <SubPlot name="sample1">  <!--定义一个“子剧情”-->
    <music src="music/music1.mp3"/>   <!--播放背景音乐-->
    <actor/>  <!--用来显示人名、立绘和头像。什么都不写表示没有立绘、头像、人名什么的-->
            我讨厌这座小镇  <!--对白用纯文本来表示-->
            因为这里满是想要忘却的回忆 <!--换行表示要等待玩家点鼠标才到下一句对白-->
    <bg img="bg/bg1.jpg"/>
            每天去学校，听听课，与朋友们闲聊，然后回到根本不想回的家里
            没有任何新鲜的事物
    <actor name="朋也"/>（这样下去，会有什么改变吗…）
                        （我的生活，今后会有什么改变吗？）
    
    <bg img="bg/bg2_sky_cloud.jpg"/>
    <actor name="声音"/>唉…
    <actor/>那是另一个人的叹息声。相比我而言，显得微弱而短促。
            我看了看旁边。
      
    <music src="music/music2.mp3"/>
    <bg img="cg/cg1_nagisa1.jpg"/>
            那里有个女生，和我一样呆呆地站着。
            看校徽的颜色，可以知道她也是三年级。
            不过，是一张陌生的面孔。
            披肩的短发，随着微风轻轻飘舞。
    <actor name="女孩"/>……
    <bg img="cg/cg1_nagisa2.jpg"/>
                        嗯…嗯…
                        ……
    <bg img="cg/cg1_nagisa3.jpg"/>  
                        你喜欢这所学校吗
    <actor name="朋也"/>哎…？
    <actor name="女孩"/>我非常非常地喜欢这里
                        但是，所有的这一切…都在改变着
                        不管是多么愉快的事，还是多么开心的事，所有这一切
                        所有这一切，都在不断改变着
    <actor/>她有些笨拙地说着
    <actor name="女孩"/>即使这样，你还会永远喜欢这里吗？
    <actor/>……
    <actor name="女孩"/>我…
    <actor name="朋也"/>只要能找到不就行了吗
  </SubPlot>
```


## 用函数来体现“语义” ##
怎样能让脚本显得更像一个“剧本”呢？剧本写出来的格式通常是这样：
  * （放音乐）
  * 女孩：你喜欢这所学校吗
  * 朋也：哎…？
  * 女孩：我非常非常地喜欢这里。但是，所有的这一切…都在改变着
先来定义几个FireML函数：
```
  <Function name="solo" doc="独白">   <!--函数名、函数的说明-->
    <funcdef>                         <!--开始函数体-->
      <actor/>                        <!--函数体中的语句-->
    </funcdef>
  </Function>

  <Function name="tomoya" doc="朋也">
    <para name="$img" doc="立绘，空值表示不显示立绘" default="" type="String"/>  <!--函数的参数-->
    <funcdef>
      <actor name="朋也" img="{$img}"/>   <!--img的值就是传入的参数-->
    </funcdef>
  </Function>

  <Function name="girl" doc="女孩">
    <funcdef>
      <actor name="女孩"/>
    </funcdef>
  </Function>
```
然后，前一个例子的脚本就可以修改成这样：
```
    <music src="music/music1.mp3"/>
    <solo/>  
    我讨厌这座小镇
    因为这里满是想要忘却的回忆
    <bg img="bg/bg1.jpg"/>
    每天去学校，听听课，与朋友们闲聊，然后回到根本不想回的家里
    没有任何新鲜的事物
    <tomoya/>（这样下去，会有什么改变吗…）
    （我的生活，今后会有什么改变吗？）

    <bg img="bg/bg2_sky_cloud.jpg"/>
    <actor name="声音"/>唉…
    <solo/>那是另一个人的叹息声。相比我而言，显得微弱而短促。<!--调用刚才定义的函数-->
    我看了看旁边。

    <music src="music/music2.mp3"/>     <!--（放音乐）-->
    <bg img="cg/cg1_nagisa1.jpg"/>
    那里有个女生，和我一样呆呆地站着。
    看校徽的颜色，可以知道她也是三年级。
    不过，是一张陌生的面孔。
    披肩的短发，随着微风轻轻飘舞。
    <girl/>……
    <bg img="cg/cg1_nagisa2.jpg"/>
    嗯…嗯…
    ……
    <bg img="cg/cg1_nagisa3.jpg"/>
    你喜欢这所学校吗                          <!--女孩：你喜欢这所学校吗？-->
    <tomoya/>哎…？                            <!--朋也：哎…？-->
    <girl/>我非常非常地喜欢这里               <!--女孩：我非常非常地喜欢这里-->
          但是，所有的这一切…都在改变着       <!--      但是，所有的这一切…都在改变着-->
          不管是多么愉快的事，还是多么开心的事，所有这一切
          所有这一切，都在不断改变着
    <solo/>她有些笨拙地说着
    <girl/>即使这样，你还会永远喜欢这里吗？
    <solo/>……
    <girl/>我…
    <tomoya/>只要能找到不就行了吗
```
它应该看起来更像一段剧本了。

## 预定义资源 ##
  * 在AVG制作时，有些资源是会被大量重复使用的，比如为数不多的背景音乐，主角的立绘等等。每次调用时都要写复杂的路径就太麻烦了。
  * AVG游戏通常有CG和音乐鉴赏功能，并且是在玩家第一次遇到该CG/音乐时显示。
  * 在音乐鉴赏时，至少要显示出音乐的标题（并不一定是文件名），有时也要显示出其它信息，如曲作者等。<br />
“预定义资源”有利于制作者方便地调用资源（有点类似于“快捷方式”），还可以为资源定义详细的属性（为了在Gallery中显示）。在定义了预定义资源之后：
```
  <Music name="1-04 町, 時の流れ, 人" src="music/music1.mp3" access="FirstMeet">
    <title>町, 時の流れ, 人</title>
    <artist>Shinji Orito, Magome Togoshi, Jun Maeda</artist>
  </Music>

  <Music name="1-05 渚" src="music/music2.mp3" access="FirstMeet">  <!--access表示某个资源在Gallery中的行为，可以是第一次遇到时显示、始终隐藏或始终显示-->
    <title>渚</title>
    <artist>Shinji Orito, Magome Togoshi, Jun Maeda</artist>
  </Music>

  <CG name="nagisa1_1" src="cg/nagisa1_1.jpg" access="FirstMeet">
    <group>1</group>      <!--group表示该CG所在的组：在CG鉴赏时，往往将一组只有表情略微不同的CG放在一起显示-->
  </CG>

  <CG name="nagisa1_2" src="cg/nagisa1_2.jpg" access="FirstMeet">
    <group>1</group>
  </CG>

  <CG name="nagisa1_3" src="cg/nagisa1_3.jpg" access="FirstMeet">
    <group>1</group>
  </CG>
```
上面例子中显示背景和立绘的语句可以改成：
```
    <music asset="1-04 町, 時の流れ, 人"/>
    <music asset="1-05 渚"/>
    <bg asset="nagisa1_1"/>
    <bg asset="nagisa1_2"/>
    <bg asset="nagisa1_3"/>
```
另外，关于音乐资源有两个设想：
  1. 由程序自动提取MP3文件的元数据（标题、曲作者等），而不用制作者再来设置。
  1. 可以把“LRC歌词”作为音乐资源的一个属性，然后程序解析LRC并且在音乐鉴赏时同步显示歌词。

## 全中文脚本 ##
因为XML完全支持中文，所以打算让天火引擎也能够支持全中文关键字版的FireML，上面的代码就可以写成这样：
```
  <子情节 名字="示例4">
    <音乐 预设="1-04 町, 時の流れ, 人"/>
    <独白/> 
    我讨厌这座小镇
    因为这里满是想要忘却的回忆
    <背景 图="bg/bg1.jpg"/>
    每天去学校，听听课，与朋友们闲聊，然后回到根本不想回的家里
    没有任何新鲜的事物
    <朋也/>（这样下去，会有什么改变吗…）
    （我的生活，今后会有什么改变吗？）

    <背景 图="bg/bg2_sky_cloud.jpg"/>
    <角色 名字="声音"/>唉…
    <独白/>那是另一个人的叹息声。相比我而言，显得微弱而短促。
    我看了看旁边。

    <音乐 预设="1-05 渚"/>
    <背景 预设="渚1_1"/>
    那里有个女生，和我一样呆呆地站着。
    看校徽的颜色，可以知道她也是三年级。
    不过，是一张陌生的面孔。
    披肩的短发，随着微风轻轻飘舞。
    <女孩/>……
    <背景 预设="渚1_2"/>
    嗯…嗯…
    ……
    <背景 预设="渚1_3"/>
    你喜欢这所学校吗
    <女孩/>哎…？
    <女孩/>我非常非常地喜欢这里
    但是，所有的这一切…都在改变着
    不管是多么愉快的事，还是多么开心的事，所有这一切
    所有这一切，都在不断改变着
    <独白/>她有些笨拙地说着
    <女孩/>即使这样，你还会永远喜欢这里吗？
    <独白/>……
    <女孩/>我…
    <朋也/>只要能找到不就行了吗
  </子情节>
```
但是，在有代码提示和代码自动完成的编辑器中，中文关键字会严重影响代码书写速度。所以天火引擎会同时支持中文关键字和英文关键字版的FireML。

## 变量、表达式、流程控制 ##
这里是FireML的一些高级用法或使用技巧：
```
    <Function name="nagisa" doc="渚">   <!--为渚定义一个函数-->
    <para name="$img" doc="渚的立绘" type="String"/>
    <para name="$古河" type="Bool" default="false" doc="如果该项为true，则名字显示“古河”而不是“渚”"/> <!--在游戏前期，渚的名字会显示为“古河”，而后期会显示为“渚”，因此设置这样一个参数，并且设置默认值为显示“渚”-->
    <funcdef>
      <if cond="$古河">               <!--判断变量“$古河”是否为真-->
        <expr>$name = "古河"</expr>   <!--如果为真，就让表示名字的变量“$name”的值为“古河”-->
        <else/>
        <expr>$name = "渚"</expr>     
      </if>
      <actor name="{$name}" img="char/nagisa/{$img}.png"/>  <!--在属性中可以嵌入变量（要用大括号包围）-->
      <!--假设渚的所有立绘都存储在char/nagisa/下，且扩展名都是png，那么就没必要每次显示渚的立绘时都输入这么多的文件夹名和扩展名-->
    </funcdef>
  </Function>

  <SubPlot name="variable">
    <tomoya/> 我有个问题
    <solo/>   我装作新生的样子，举手提问
    <nagisa img="微笑" 古河="true"/>好的，请问  <!--这里显示出的立绘是“char/nagisa/微笑.png”-->
    
    <select return="$问题">                     <!--选择框-->
      会演怎样的话剧呢？                        <!--如果玩家选择第一个选项，则“$问题”的值将为0，以此类推-->
      海报上画的是什么东西？
      你喜欢哪种类型的男生？
    </select>
   
    <switch expr="$问题">                       <!--分支跳转-->
      <case value="0">
        <tomoya/>会演怎样的话剧呢？
        <solo/>虽说都是话剧，但却也种类繁多…大概。
      </case>
      <case value="1">
        <tomoya/>海报上画的是什么东西？
        <solo/>我想这绝对会被问到的，所以不能坐视不管。
      </case>
      <case value="2">
        <solo/>也可能会有人要开她的玩笑，那该怎么回答呢？
        <tomoya/>你喜欢哪种类型的男生？
      </case>
    </switch>
    
  </SubPlot>
```
表达式支持基本的算术和逻辑运算，也支持字符串的连接，例如：
```
  <expr>
	$a = ($b + 3) * 5^2;
	$c = $b > 0;
	$str = "$a is " + $a;
  </expr>
```

## 代码提示和自动完成IntelliSense ##
目前的代码提示和自动完成是为FireML定义了一套完整的XML Schema后，利用Visual C#对XML的IntelliSense来完成的。对于用户自定义的函数和预定义资源，利用一个小程序来动态生成相应的XSD从而也能被编辑器识别。
  * 编辑时的XML语法错误以及FireML语法错误和部分逻辑错误会被编辑器实时标注出来，就像Word的拼写和语法检查。
![http://firefromheaven.googlecode.com/svn/wiki/attachments/Intelli4.jpg](http://firefromheaven.googlecode.com/svn/wiki/attachments/Intelli4.jpg)
  * 键入“<”符号后，会显示出当前可用的所有关键字供选择。
> > ![http://firefromheaven.googlecode.com/svn/wiki/attachments/intelli1.gif](http://firefromheaven.googlecode.com/svn/wiki/attachments/intelli1.gif)
  * 键入“<元素名 ”后，会显示出该元素的参数供选择。
![http://firefromheaven.googlecode.com/svn/wiki/attachments/intelli2.gif](http://firefromheaven.googlecode.com/svn/wiki/attachments/intelli2.gif)
  * 在选择框中选择时，会显示出相应词条的帮助文档。
  * 把光标放在某个关键字上，会显示出相应的帮助文档。
  * 引用预定义资源时，会显示出制作者定义好的、相应类型的预定义资源列表。
![http://firefromheaven.googlecode.com/svn/wiki/attachments/Intelli3.gif](http://firefromheaven.googlecode.com/svn/wiki/attachments/Intelli3.gif)
  * 用户的自定义函数的IntelliSense和FireML的关键字相同。
  * 其它很多不易用语言描述的特性。