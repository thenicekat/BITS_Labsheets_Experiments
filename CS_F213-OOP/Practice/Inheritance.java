class Timepass {
    Timepass(){
        System.out.println("Timepass");
    }
}

class MoreTimepass extends Timepass {
    MoreTimepass(){
        System.out.println("More Timepass");
    }

    @Override
    public String toString(){
        return "Icecream";
    }
}

public class Inheritance {
    public static void main(String args[]){
        MoreTimepass mt = new MoreTimepass();
        System.out.println(mt.toString());
    }
}
