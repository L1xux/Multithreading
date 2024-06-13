## Notice
In this program, I didn't make my own udp server but i refer to the code of my instructor. However, rest of them related to multithread are made by me.


## How to Compile and Run the Program

To compile and run the program, follow these steps:

### Step 1: Compile the Program

1. Open a terminal and navigate to the directory where the `compile.sh` script is located.
2. Run the following command to compile the program:
   ```sh compile.sh```
This will compile the program and generate executable files: listener_main.exe and udp_sender.exe.

### Step 2: Run the Program
Open Two Terminal Windows:

You need two terminal windows to run both the listener and the sender.
#### Run the Listener:
In the first terminal window, execute the listener_main.exe:
```./listener_main.exe```

#### Send Text Using the Sender:
In the second terminal window, you can send text to the listener using udp_sender.exe. Use the following format to send text to a specific port (e.g., 3000 or 3001) with a message of 16 characters or less:
```./udp_sender.exe 127.0.0.1 3000 "your_text_here"```

For example:
```./udp_sender.exe 127.0.0.1 3000 "Hello, World!"```

The listener_main.exe running in the first terminal should receive and display the text message sent from the second terminal.
