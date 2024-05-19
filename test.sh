#!/bin/bash
#set -x
set -euo pipefail

# Temporary file to capture server output
output_file=$(mktemp)
message="If it's like this then it works😈😈😈😈😈  "

# Start the server in the background and redirect output
./server &> "$output_file" &
server_pid=$!

# Can cause problems if server is not ready?
sleep 1
# Now run the client with the server's PID
./client "$server_pid" "$message" > /dev/null

wait $!
wait $server_pid

# Optionally, compare the output with expected output
expected_output="$message"
if grep -q "$expected_output" "$output_file"; then
    echo "Test passed: Output as expected"
else
    echo "Test failed: Output not as expected"
fi

# Clean up
rm "$output_file"
