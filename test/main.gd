extends Node2D

onready var ser = preload("res://GDSerial/GDSerial.gdns").new()

const port = "/dev/ttyACM0"

func _ready():
	var ports = ser.list_ports()
	if not ports.has(port):
		print("Cannot find port")
		get_tree().quit()
		return
	
	print("Connecting to " + port)
	ser.setPort(port)
	ser.open()
	print("Is open: " + str(ser.isOpen()))
	
	var data = StreamPeerBuffer.new()
	data.put_u8(253)
	data.put_u8(0)
	data.put_u8(0)
	data.put_data("SSTAT".to_ascii())
	data.put_u8(66)
	data.put_u8(75)
	data.put_u8(254)
	
	print("Write: " + str(ser.write(data.data_array)))
	print("Wait 1 second before read")
	OS.delay_msec(1000)
	var a = ser.available()
	print("Available: " + str(a))
	var ack = ser.read(a)
	print("Read: " + str(ack))
	
	print("Closing port.")
	ser.close()
	
	get_tree().quit()
