public class EightQueens{
    
    private String board[][] = new String[8][8];

    private void removeQueen(int col, int row){
        board[col][row] = "";
    }

    public void displayBoard(){
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                System.out.println(board[i][j]);
            }
            System.out.println("\n");
        }
    }

    public void placeQueens(){
        
    }


}