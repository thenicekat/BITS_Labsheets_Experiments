class InvalidArgumentException extends Exception {
    public InvalidArgumentException(String message) {
        super(message);
    }

    public String toString() {
        return "Exception: Code: 333: Invalid Argument Exception";
    }
}

class PP2 {
    public static void print(String x) throws InvalidArgumentException {
        if (x.equals("NO")) {
            throw new InvalidArgumentException(x);
        } else {
            System.out.println(x + " is valid.");
        }
    }

    public static void main(String[] args) {
        int length = args.length;
        for (int i = 0; i < length; i++) {
            try {
                print(args[i]);
            } catch (InvalidArgumentException e) {
                System.out.println(e);
            }
        }
    }
}