extends Node2D

onready var ser = preload("res://GDSerial/GDSerial.gdns").new()

func _ready():
	print(ser.list_ports())
