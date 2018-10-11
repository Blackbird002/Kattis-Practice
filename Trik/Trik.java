import java.util.Scanner;

class Trik{
    //Each array element is a cup (where the ball will be located)
    public static void main(String args[]){

        String inputStr = "";

        Scanner sc = new Scanner(System.in);
        while(sc.hasNextLine()){
            inputStr = sc.nextLine();
            TrikSolver solver = new TrikSolver(inputStr);

            //Print the result to the screen
            System.out.println(solver.solve());
        }                        
    }
}

class TrikSolver{
    private String inputString;
    private boolean cup[] = {false,false,false};

    public TrikSolver(){
        inputString = "";

        //Initial Position of Ball
        cup[0] = true;
    }

    public TrikSolver(String input){
        inputString = input;

        //Initial Position of Ball
        cup[0] = true;
    }

    public int solve(){
        //Initial Position of the ball
        int locationOfBall = 1;

        for(int i = 0; i < inputString.length(); i++){
            if(inputString.charAt(i) == 'A')
                moveA();
            else if (inputString.charAt(i) == 'B')
                moveB();
            else
                moveC();
        }
        //Done doing the sorting

        //Check the cups
        if(cup[0] == true)
            locationOfBall = 1;
        else if(cup[1] == true)
            locationOfBall = 2;
        else
            locationOfBall = 3;

        return locationOfBall;
    }

    //Cup movement functions
    private void moveA(){
        boolean temp = cup[0];
        cup[0] = cup[1];
        cup[1] = temp;
    }

    private void moveB(){
        boolean temp = cup[1];
        cup[1] = cup[2];
        cup[2] = temp;
    }

    private void moveC(){
        boolean temp = cup[0];
        cup[0] = cup[2];
        cup[2] = temp;
    }
}