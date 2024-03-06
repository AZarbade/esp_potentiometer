import serial

# Configure the serial port
ser = serial.Serial('/dev/ttyUSB0', 115200)  # Replace with your serial port and baud rate

# Open the text file for writing
with open('potentiometer_data.txt', 'w') as f:
    while True:
        line = ser.readline().decode('utf-8').strip()
        if line:
            # Write the reading to the text file
            f.write(line + '\n')
