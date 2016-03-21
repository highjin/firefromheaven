

### TODO ###
  * (FINISH) AssetASTNode, 里面包含AssetDataBase和Location、ID，把Asset归到AST树里
  * (FINISH) Deserialize函数用模板
  * (FINISH) 实现并使用IDataCheckHelper
  * ActionLayer名字错了！应该是ActorLayer

### FINISH Asset很有问题 ###
  * 尽量减少添加Asset类型时的操作数目
  * 考虑只用一个Dictionary来存储所有类型的Asset
  * 即使是不同类型的Asset也不能重名

### 剧情历史记录 ###
  * GlobalRuntimeData
    * GlobalScope
    * 已读过的文本的AST ID
    * 已出现过的Asset的名字
  * RuntimeData
    * 文本历史记录的AST ID序列
  * RuntimeData和GlobalRuntimeData通过ContentManager来Save/Load

### `<Advanced>`标签 ###
  * 高级功能必须被`<Advanced>`标签包括才会在代码提示中显示出来
  * 高级功能包括：
    * Layer
    * Transition
    * Animation
  * 简单的Effect不是高级功能
  * 高级功能主要通过局部序列化来解析

### 图层的概念 ###
  * 所有没有用户交互的图像全部使用图层来表示
  * 图层没有名字，只有ID号。ID号大的会盖住ID号小的
  * 图层内含有一个Image对象
  * 规定图层总数，并按区域划分
    * 0~7 背景
    * 8~15 效果
    * 16~23 立绘
    * 24~31 未定义
  * 背景是图层
    * `<bg>`对应0号图层
  * 立绘是图层
    * `<actor>`对应16号图层
    * `<ActionLayer>`按照声明顺序为其分配立绘图层
  * 大部分的效果都可以是图层
    * 大部分的Effect可以抽象成Image对象
    * 每一种Effect对应一个固定的效果图层
  * 用户可以用`<layer>`直接控制图层
  * 所有的特殊Image必须通过图层来设置
  * LayerAsset
  * 每个图层都支持Transition
    * Image提供一个virtual bool IsShaderRequired，保证Transition不会和Image抢shader。冲突则报运行时错误
    * 效果图层禁止Transition
    * bg和actor加trans属性，直接指定transition名字；解析时将其解析为TransitionData。这样的transition只作用一次
    * `<Transition layer="xxx"><xxxTransition (parameter/></Transition>` 为图层指定永久性的Transition

### TODO Build Event有BUG ###
  * 路径中不能有空格
  * 路径中的Debug应该换成$(ConfigurationName)

### 局部序列化结点 ###
  * 暂停
  * 设置标题栏
  * 图片叠加序列动画`<Actor>`和`<CG>`中包含ImageOverlapAnimationData
  * 动画AnimationData

### 添加Asset类型 ###
  * Animation (AnimationData序列化 + Name)
  * Transition (TransitionData序列化 + Name)
  * 添加Asset要改：AssetXSDGenerator, IAssetVisitor, AssetBuilder

### 局部序列化自动XSD ###
  * 编译前调用xsd.exe生成XSD
  * 写一个程序，对生成的XSD做修改（去掉element, 改targetNamespace），存到XSD文件夹
  * FireML.xsd加include

### 自动对口型 ###
  * 识别音频文件中的音节
  * 参考对白脚本的字数

### 脚本局部序列化 ver2 ###
  * 不直接序列化控件，而是序列化Data对象。Data对象放入SerializableLibrary，不依赖XNA。FireEngine和FireMLEngine依赖之。
  * Data对象的变量均为internal，有public的get/set
  * 控件中包含Data对象。例如EffectImage包含EffectImageData。后者包含一个TextureImageData
  * Data对象自带static deserialize函数，接受XML片段。（避免了friend）
  * 包含Data对象的控件提供接受Data对象的构造函数
  * 考虑让所有Data类继承自一个基类

### 3D雨雪效果 ###
  * 生成带Z轴坐标的背景图，指定立绘的Z轴坐标

### 脚本局部序列化（初稿） ###
  * 所有能由脚本序列化得到的控件，放入单独的dll里SerializableLibrary，依赖XNA。FireEngine和FireMLEngine均依赖之。
  * SerializableLibrary对FireEngine和FireMLEngine是internal friend
  * 增加AST结点ObjectNode，存入被反序列化的object
  * 能被序列化的对象的属性均设为internal（或public）
  * 问题：是否会与DependenctyObject机制冲突？
  * XSD中将某个抽象基类定义为Type。例如Image、Animation等。Type内包括以子类命名的元素

### 实用的杂项 ###
  * 考虑视频支持简单的控制功能（播放、暂停、进度条），可以设置是否允许用户控制
  * 暂停：等待指定的时间后再执行下一条指令。可以设置是否可以由用户点击鼠标而跳过等待。
  * 用预定义函数，调用暂停功能，实现标题LOGO显示等。
  * 允许脚本修改窗口的标题栏

### 音乐Gallery的视觉效果 ###
  * 指定一些文件，幻灯片播放（像Picasa的屏保，提供几种切换方式）
  * LRC歌词
  * 歌曲信息
  * 滚动字幕
  * 考虑顺便做个屏保
  * FireML应支持“开启Asset”，即不显示该Asset但使其能够出现在Gallery中

### 界面“模块” ###
  * 自定义：是否显示这一项

### 图片序列动画 ###
  * 图片序列动画：一个背景图层+若干个动画层。考虑给PS做一个脚本，使Background图层为背景层，每个Layer为动画层。
  * 考虑在脚本里实现Timer
  * 图片叠加模式（Hue，Color，正片叠底）

### 小游戏接口 ###
  * 可以修改StackScope(封装!)
  * 基类提供和引擎的交互,如存档、跳出小游戏等

### 字体的半增量编译 ###
  * 设置常用字库，预先编译一个字体文件
  * 从脚本中读取未被包含的字，编译成另一个字体文件
  * 运行时检查哪个字体中含有指定的字
  * 有问题！一次Sprite必须用同一个字体

### 读音乐文件的Meta ###
  * 考虑自动读取音乐文件的Meta而不用在预定义资源里设置标题等信息

### TODO文档要点 ###
  * Float不能判等
  * 变量作用域问题
  * 如果一个函数参数类型是Expression的，则其Default被认为是Auto的
  * 小于号要用&lt;
  * 参数字串中，如果参数中含“,”，则要加引号，否则不用加

### 函数中的变量 ###
  * 只有特定类型的属性支持变量，例如：资源路径、预定义、名字等
  * 在上述属性中，若出现{$varname}，则替换为相应的变量
  * 不检查含有变量的路径、预定义的存在性

### 带参数的Visit模式 ###
```
Accept(IVisitor visitor, param args);
Visit(FunctionDef functionDef, object[] args);
```

### Transitioin的XML ###
  * 各种Transition的参数定义为XSD
  * 可以通过Asset来调用Transition。预先写好一些Asset，用户也可以自己定义Transition Asset

### Animation and Transition ###
  * 模仿WPF实现DependencyObject和DependencyProperty
    * 如果DependencyProperty只在绘图时使用，如Background、Opacity，则不需要在Update时刷新
    * 如果DependencyProperty会影响其它属性的值，如Margin影响Position，则需要在Update时刷新受影响的值
  * Transition是类型为Image的Animation。
  * Image类似于WPF中的ImageSource概念。Image可以是BitmapImage, TransitionImage, EffectImage等。
    * TransitionImage中包含Transition对象，调用Transition的Draw。
      * OpacityTransition
      * MapTransition
      * etc.
    * EffectImage实现对Effect计算结果的缓存
  * TransitionAnimation的初始值为原图，终止值为新图，BitmapImage；中间值为TransitionImage


### Hit Test ###
  * ContentControl组成VisualTree，ScreenManager作为根节点
  * 按ZIndex从大到小排序；从根节点做深度优先搜索
  * this.HitTest()以this为根节点; ScreenManager.HitTest()做全局的HitTest
  * 策略：
    * 找到第一个非叶节点：Button.HitTest()鼠标是否在Button的范围内
    * 找到第一个叶节点：获得最上层的元素
    * 自定义策略（仿WPF，可以先不做）


### 表达式 ###
  * 在编译时把表达式也转成AST树来存储，以便进行编译时检查

### 内容预定义 ###
  * 由asset的XML生成相应的XSD？
    * MusicAsset, VideoAsset, CGAsset, Asset。指定了类型就只能从该类型里选，Asset可以从所有类型里选
  * 音乐
    * 元数据
    * 考虑解析LRC歌词文件，播放音乐时可以指定是否显示歌词……
  * 图片（CG）
  * 动画

### 脚本引擎 ###
  * 把AST树当做“脚本”使用
  * AST提供方法来通过一个字符串（或别的什么类型）来修改指令指针（树结点的编码？），以支持存档、读档的序列化
  * 指令指针即指向AST树的一个结点（是逻辑位置，而不是内存中的引用，以支持序列化）
  * 引擎在Deserialize后，将之前先被Deserialize的AST树的引用赋给引擎
  * 调用栈中记录当前作用域对应的指令指针、退栈时下一个要执行的指令指针等 （即控制信息）
  * 执行思路和原来的Interpreter基本相同（只是不用解析了）。也需要FuncCaller（就像是Decoder...）

### 编译器 ###
  * 做一个单独的编译器，由XML脚本生成一个二进制序列化的AST树（字节码……）
    * 或者是把编译器集成到ContentPipeline的编译里去？
  * 特别注意处理`<actor>`和对白
  * 做适当的语义检查，如break, continue
  * 内容检查：检查每一个对内容的引用是否存在、类型是否匹配、是否是引擎支持的文件格式
  * FireEngine.XMAContent实现接口IContentChecker供编译器使用
  * XSD文件仍然存放在用户的工程里（编译时不输出）
  * 自定义XNA的ContentPipeline去读取AST树
  * 中文脚本的翻译工作

### 界面定义的初步设想 ###
  * 所有用到的图片放在XNAContent.FireFromHeaven里，专用一个System文件夹
  * 所有用到的常量存在一个类里，该类可以序列化为XML以供修改

### XSD Generator ###
  * 若不支持多文件，可以每次把固有的拷贝一次
  * 字体：固定常用字（希腊神话！）；如果比常用字多，则再增加
    * 考虑把常用字表做成剧本XML的一部分

### 与图形引擎分离？ ###
  * 以XNA为框架，把要用到的所有功能做成接口，再用XNA来实现
  * 启动：IGameEngine.Begin()之类的

### 资源包问题（续） ###
  * 实现接口：
    * 内容载入：IContentManager
    * 显示：ISprite
    * 声音：IMusic, IVideo, ISound（名字待定）
    * 内容类型：IImage, IFont, ISound...（待定）

### 滚动字幕 ###
  * 用于显示说明、版权声明什么的

### 特效和图层 ###
  * 考滤加入水波、光影等高级特效。用一个Mask图片来定义特效的作用范围。（如表示图片中一个水池的位置)
  * 考虑引入“图层”或者ZIndex的概念
  * 给特效按计算复杂度分级，以便让用户选择视觉效果等级

### VisualObject修正 ###
  * 考虑UIElement extends VisualObject，后者没有事件处理，不接收用户输入（如ToolTip）

### 学习WPF的GUI框架 ###
  * 基本不考虑用WPF写了
  * VisualObject, Container
所有屏幕上可见的东西继承VisualObject
```
class VisualObject 
{
    public boolean isInBound(Point p);
    public boolean isHitTestVisible();
    public virtual void fireHitEvent(MouseEvent e);  //这里不判断鼠标是否在区域内
    //触发Click, OnMouseOver, OnMouseOut等事件
    //在该object无法触发事件时，注意处理OnMouseOut等事件
}
```
Container中可以包含其它的VisualObject (似乎是个什么设计模式……）
```
class Container : VisualObject
{
    private List<VisualObject> children;  //元素按照Z轴顺序排序，显示在上面的排序在前
    
    public override void fireHitEvent(MouseEvent e)
    {
        foreach(VisualObject c : children)
            if(isHItTestVisible() && isInBound(e.Position))
            {
                children.fireHitEvent(e);
                break;
            }
         base.fireHitEvent(e);
    }
}
```
Screen是Container. ScreenManager触发可接收事件的VisualObject的fireHitEvent
  * Animation

### WPF? ###
考虑用WPF做游戏？调查以下问题：
  * 需要安装.Net Framework 3.5
  * Pixel Shader及其速度
  * 字体和特效

### 脚本编辑器之打包 ###
需要游戏制作者安装Visual C# Express Edition（400多M，有中文版，免费，不用破解）和XNA Game Studio（60多M，免费），但是\*完全不用\*运行这些东西。还需要安装Java Runtime Environment（大多数系统应该已经自带了）。

避免VS不是不可能，但工作量太大了，XNA提供的字体、音频、视频功能全都不能用，需要找别的库或者自己实现一遍。其中字体好像是最要命的……
  * 脚本：每次“Run”时编译，FireML Compiler
  * 图片：有更新时打包；内容文件紧凑排列，索引文件可以用序列化
  * 声音：有更新时运行Content Pipeline Compiler
  * 视频：有更新时运行Content Pipeline Compiler
  * 开源后，简单加密似乎是不可能了
  * 发布：将需要的文件都拷贝一份出来即可（或者说去掉脚本编辑器部分即可）

### XML脚本的解析 ###
  * 编译：把XML树的结点转换为语法树结点；语法树结点有compile方法可以生成相应的statements序列
  * 对if..else...，for，while等结点，调用compile后返回带goto的statements（像汇编那样）
  * 用堆栈记录函数及当前语句（就像BP、IP）。调用函数入栈，返回时退栈。
  * MainPlot，SubPlot当做函数处理
  * 函数应该支持返回值。定义时:
```
<function name = "func">
    <return>表达式</return>
</function>
```
  * 调用时：
```
<function name = "func" return = "$a"/>
```
  * if...else考虑再设计一下

### RCP脚本可视化编辑器 ###
  * XML文法 (DTD还是XSD？XMLBuddy够用吗（主要是Auto Formatting的问题？可以禁掉它。。。）
  * 支持中文关键字的XML（考虑中英文关键字一一对应，都提供支持）
  * 系统函数表/变量表/用户自定义函数表，双击后添加到代码中。对某些特殊的函数（如地图选择、动画等）提供可视化编辑
  * 添加资源（图片、声音、视频、无预览的其它资源）（相对路径问题怎么解决）
  * 当用户定义了一个Function时，动态修改DTD文件以支持自动完成
  * 参考编译原理中对Decaf语言的面向对象描述（词法、语法分析看来是不用了）
  * Eclipse的Package面板、“运行”按钮等

### 全屏幕渐变 ###
成一个带透明度的图案盖上去即可，避免多次Shader

(对一个全黑填充做shader或者简单的变换）

对话框的出现和消失：可以让对话框有自己的Shader

### 一些AVG引擎的设想 ###
研究ContentPipeline

用XML表示界面（入口、主界面、UI背景图、Save/Load等，主要记坐标/布局和背景图）

用XML表示历法？？

### 全屏渐变、全屏效果方案二 ###
ScreenManager接到请求后，停止所有的Update，并将最后一帧渲染到一个RenderTarget缓存，然后对此静态图片做渐变或加效果

### No Title ###
图形引擎接口，以便适应XNA的更新，甚至将来提供对OpenGL或者GUI+的支持。接口！！！

考虑调用Windows的API来显示文字（放弃XBOX360吧）

预渲染的文字特效！！！

什么时候开始做架构设计呢……

### 局部变量的实现 ###
```
Stack<Map<Variable> > localVars;
```

### No Title ###
ITransitionable和IAnimationable接口设计

### 历法系统 ###
```
interface ICalendar {
    public Parse(String str);
    public ToString();
    public ICalendar operator+(int days);
    public ICalendar operator++();
    ...
}
```

### 内容编译 ###
资源类型：
  * 图片
  * 音频
  * 视频
  * 脚本
  * 资源定义
  * ...

做一个IContentManager，先实现为使用XNA的Content Pipeline（要求开发者安装Visual C# Express（用中文版） + XNA
自定义类：IImage, ISound, IVideo, ...

### 脚本编辑器 ###
RCP + Eclipse的插件“XML Buddy”，加入识别函数定义、（菜单）添加标签、选择资源文件等。
如果决定不用Content Pipeline而使用资源包，也可以在脚本编辑器中加入制作资源包的功能