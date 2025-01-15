# Minitalk

Minitalk is a project from the 42 curriculum that demonstrates the use of interprocess communication (IPC) in Unix-like operating systems. The goal of this project is to create a simple communication system between a client and a server using signals.

---

## Table of Contents
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Technical Details](#technical-details)
- [Project Structure](#project-structure)
- [Error Handling](#error-handling)
- [License](#license)

---

## Features

- Communication between a client and a server using Unix signals.
- Send and receive messages encoded as binary data via signals (`SIGUSR1` and `SIGUSR2`).
- Error handling for invalid input or signal delivery failures.
- Smooth operation for message lengths of varying sizes.

---

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/minitalk.git
   cd minitalk
   ```

2. Build the project:
   ```bash
   make
   ```

3. The `make` command will generate two executables:
   - `server`
   - `client`

---

## Usage

### Starting the Server

Run the server to start listening for messages:
```bash
./server
```
The server will display its Process ID (PID). Note this PID for the client.

### Sending a Message with the Client

Use the client to send a message to the server:
```bash
./client [server-pid] "Your message here"
```

Example:
```bash
./client 12345 "Hello, World!"
```

### Output
- The server will display the received message in real-time.

---

## Technical Details

- **Signals Used:**
  - `SIGUSR1`: Represents a binary `0`.
  - `SIGUSR2`: Represents a binary `1`.

- **Encoding and Decoding:**
  - The client encodes each character of the message into binary and sends the bits one by one to the server using the appropriate signal.
  - The server decodes the binary data and reconstructs the original message.

- **Acknowledgments:**
  - The server sends acknowledgments to the client for each received character, ensuring synchronization and reliability.

- **Error Handling:**
  - Detect invalid PID or signal delivery failures.
  - Handle edge cases, such as empty messages or excessively long messages.

---

## Project Structure

```
minitalk/
├── src/
│   ├── server.c       # Server implementation.
│   ├── client.c       # Client implementation.
│   ├── utils.c        # Utility functions (e.g., signal handling, encoding/decoding).
├── includes/
│   └── minitalk.h     # Header file with prototypes and constants.
├── Makefile           # Build system.
└── README.md          # Project documentation.
```

---

## Error Handling

Minitalk includes robust error handling to address potential issues:

- **Invalid PID:**
  - The client verifies the server PID before attempting communication.

- **Message Integrity:**
  - The server ensures that all bits are received and decoded correctly.

- **Signal Failures:**
  - Appropriate checks are in place for undelivered signals or interrupted communication.

- **Memory Safety:**
  - Proper memory management ensures no leaks or corruption (validated with tools like `valgrind`).

---

## License

This project is licensed under the MIT License. See the `LICENSE` file for details.

---

Happy coding! 🚀
