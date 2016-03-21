### Background ###
```
Background.DrawEffect()
Background.SetEffectedTexture()
foreach(characters) c.DrawEffect(), c.SetEffectedTexture();
Background.Draw()
foreach(characters) c.Draw()
```

### 有关Effect的纠结问题 ###
考虑：

所有元素渲染到RenderTarget，最后装配

每一个Screen有一个RenderTarget（可以加全屏Effect）

背景、人物的Effect有RenderTarget，先Effect再Transition（可以解决冲突问题）
Effect要支持动态

问题：

RenderTarget改变后已绘制的是否丢失？若是，只有ResolveBackBuffer？

答：是，用GetTexture

### Package： ###
对于需要编译的Content：

直接将VS编译好的Content文件夹，按照子目录打包即可。

检查当前文件是否比资源包文件新，若新则修改Package文件（添加/删除）

将Package程序作为Pose Compile Event