"""
Create a mininet topology with 3 hosts machines (one HTTP client H1 and two HTTP server 
H2 and H3) and three switches in parallel to which all the 3 hosts are connected. Run http servers 
on H2 and H3, assume H2 and H3 server contains file h1.txt (content: this is h1) and file h2.txt 
(content: this is h2) and send an http request from H1 to both H2 and H3 to get the files on H1, 
and analyze the HTTP traffic through Wireshark
"""

from mininet.node import Host,OVSSwitch,Controller 
from mininet.link import Link 

h1 = Host('h1')
h2 = Host('h2')
h3 = Host('h3')
s1 = OVSSwitch('s1', inNamespace=False)
# s2 = OVSSwitch('s2', inNamespace=False)
# s3 = OVSSwitch('s3', inNamespace=False)
c0 = Controller('c0', inNamespace=False)

# Connect the hosts to the switches
Link(h1, s1)
Link(h2, s1)
Link(h3, s1)
# Link(h1, s2)
# Link(h2, s2)
# Link(h3, s2)
# Link(h1, s3)
# Link(h2, s3)
# Link(h3, s3)

# Connect the three switches in parallel
# Link(s1, s2)
# Link(s2, s3)
# Link(s3, s1)

# Set the IP addresses of the hosts
h1.setIP('10.0.0.1/24')
h2.setIP('10.0.0.2/24')
h3.setIP('10.0.0.3/24')

# Start the network
c0.start()
s1.start([c0])
# s2.start([c0])
# s3.start([c0])

# Print the IP addresses of the hosts
print(h1.IP())
print(h2.IP())
print(h3.IP())

# Run http servers on H2 and H3 and serve files h1.txt and h2.txt
h2.cmd('python3 -m http.server 80 &')
h3.cmd('python3 -m http.server 80 &')
h1.cmd('xterm')


# You can run this script by typing: sudo python Q3.py