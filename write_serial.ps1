$port= new-Object System.IO.Ports.SerialPort COM5,115200,None,8,one
$port.open()
$port.WriteLine("Hello world")
$port.Close()