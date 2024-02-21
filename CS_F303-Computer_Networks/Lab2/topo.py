from mininet.topo import Topo


class MyTopo(Topo):
    def build(self):
        # Add hosts and switches
        h1 = self.addHost("h1")
        h2 = self.addHost("h2")
        h3 = self.addHost("h3")
        s1 = self.addSwitch("s1")
        s2 = self.addSwitch("s2")
        s3 = self.addSwitch("s3")

        # Add links
        self.addLink(h1, s1)
        self.addLink(h2, s1)
        self.addLink(h3, s1)
        self.addLink(h1, s2)
        self.addLink(h2, s2)
        self.addLink(h3, s2)
        self.addLink(h1, s3)
        self.addLink(h2, s3)
        self.addLink(h3, s3)


topos = {"mytopo": (lambda: MyTopo())}
