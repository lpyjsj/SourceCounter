[=>主页](SourceCounterCN.md)

## Counting settings and Start counting ##

![http://boomworks.googlecode.com/files/SourceCounter-3.4-en-detail-usage.jpg](http://boomworks.googlecode.com/files/SourceCounter-3.4-en-detail-usage.jpg)

  * 统计设定区域
    * “添加...” - 打开“添加源代码目录”对话框
    * “删除” - 删除选中的源代码目录
    * “选择” - 打开“选择代码类型”对话框
    * “递归统计子目录” - 统计所有的子目录
    * “更多设定...” - 打开“更多设定”对话框

  * 状态 - 显示统计状态
  * 开始/停止 - 开始/停止统计

  * 统计结果区域
    * “保存...”- 打开“保存文件”对话框

  * “检查更新...”- 打开检查更新网页
  * “界面语言...”- 打开“语言选择”对话框
  * “关于...” - 打开“关于”对话框
  * “退出” - 退出程序

## Analysis and Refresh Result ##

![http://boomworks.googlecode.com/files/SourceCounter-3.4-en-report-usage.jpg](http://boomworks.googlecode.com/files/SourceCounter-3.4-en-report-usage.jpg)

### Analysis Parameter ###

**本工具默认给出各种质量指标和工数、成本指标等都是业内的参考值，用户可以根据各个公司、个人的情况调整。**

  * 质量指标设定
    * 单元测试（Unit Testing）
      * 用例密度（Cases Density）：设定每千行代码要做的测试用例数。50为本工具的参考值。
      * 缺陷密度（Defects Density）：设定每千行代码预计测试出来的缺陷数。10为本工具的参考值。
    * 结合测试（Integration Testing）
      * 用例密度（Cases Density）：设定每千行代码要做的测试用例数。20为本工具的参考值。
      * 缺陷密度（Defects Density）：设定每千行代码预计测试出来的缺陷数。2为本工具的参考值。

  * 工数和成本分析的设定
    * 编码生产率：一个人一个月生产的代码行数。4000为本工具的参考值。
    * 一个人月的人日数：软件工程学里面的一个人月里包含的人日数（天数）。20为本工具的参考值。
    * 一个人月的成本：一个人一个月的成本，不光是薪水，还有公司的隐性成本。10000美元为本工具的参考值（这个一定要调整，不然后果不堪设想 :-）

## 代码类型相关的对话框 ##

  1. 选择代码类型 对话框
    * ![http://boomworks.googlecode.com/files/SourceCounter-SelSrcTypeDlg-CN-2.4.png](http://boomworks.googlecode.com/files/SourceCounter-SelSrcTypeDlg-CN-2.4.png)
      * “选择所有类型”：选择或非选择所有的扩展名
      * “添加...”：打开“文件类型设定-添加 对话框”
      * “编辑...”：打开“文件类型设定-编辑 对话框”
      * “删除”：删除当前选择的统计代码扩展名
      * “OK”：确认选择内容无误，并关闭对话框
      * “Cancel”：取消选择，并关闭对话框。
  1. 文件类型设定-添加 对话框
    * ![http://boomworks.googlecode.com/files/SourceCounter-AddSrcTypeDlg-CN-2.4.png](http://boomworks.googlecode.com/files/SourceCounter-AddSrcTypeDlg-CN-2.4.png)
      * “扩展名”：填写要添加的扩展名，例：.cpp
      * “描述”：填写扩展名的描述信息
      * “源代码语言风格”：选择所填扩展名文件的语言风格
      * “风格描述”：填写风格描述
      * “单行注释”：不可更改
      * “多行注释开始”：不可更改
      * “多行注释结束”：不可更改
      * “OK”：确定，并关闭对话框
      * “Cancel”：取消，并关闭对话框
  1. 文件类型设定-编辑 对话框
    * ![http://boomworks.googlecode.com/files/SourceCounter-EditSrcTypeDlg-CN-2.4.png](http://boomworks.googlecode.com/files/SourceCounter-EditSrcTypeDlg-CN-2.4.png)
      * “扩展名”：同上
      * “描述”：同上
      * “源代码语言风格”：同上
      * “风格描述”：同上
      * “单行注释”：同上
      * “多行注释开始”：同上
      * “多行注释结束”：同上
      * “OK”：同上
      * “Cancel”：同上

## 联系我们(Contact) ##

  * [boomworks@gmail.com](mailto:boomworks@gmail.com)