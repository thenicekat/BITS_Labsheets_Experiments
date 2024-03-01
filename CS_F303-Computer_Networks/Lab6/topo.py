from mininet.topo import Topo


class MyTopo(Topo):
    def build(self):
        self.addHost("h1")
        self.addHost("h2")

        self.addSwitch("s1")

        self.addLink("h1", "s1")
        self.addLink("h2", "s1")


topos = {"mytopo": (lambda: MyTopo())}
