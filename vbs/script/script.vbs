  set app = CreateObject("eugen.Application")
  
  app.CreateThisFile("C:/Users/EUgen/Desktop/Component/component/files/test.txt")
  app.CreateThisFile("old file")
    
  app.testInt = 11
  p = app.testInt()
  WScript.Echo(p)

  WScript.Echo(app.testInt)

  app.testInt = 111
  p = app.testInt
  WScript.Echo(p)
