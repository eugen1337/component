  set app = CreateObject("eugen.Application")
  
  app.CreateThisFile("C:/Users/EUgen/Desktop/Component/component/files/vbTest.txt")
  app.CreateThisFile("C:/Users/EUgen/Desktop/Component/component/files/old file")

  app.CreateFolder("C:/Users/EUgen/Desktop/Component/component/files/vbCreatedThis")
  
  app.testInt = 11
  p = app.testInt()
  WScript.Echo(p)

  WScript.Echo(app.testInt)

  app.testInt = 111
  p = app.testInt
  WScript.Echo(p)
