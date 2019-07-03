package javaapplication2;

import java.awt.Color;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.Scanner;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JPanel;

public final class ConnectFour extends JPanel {

    public JFrame window;
    JButton buttons[][];
    GridLayout grid;
    ArrayList<ArrayList<Cell>> gameBoard;
    private char playerOption;
    private char userStone;
    private int tempComputerMove;
    private boolean computerMove;
    private boolean player;
    private boolean game;
    private boolean winComputer, winPlayer;
    private int playerNo;
    private int tempTargetCol;
    private int gameBoardHeight;
    private int gameBoardWidth;
    private static final int MINIMUM_BOARD_HEIGHT = 4;
    private static final int DECIMAL_LOWER_A = 97;
    private static final int WINNING_NUMBER = 4;
    private static final int ARTIFICAL_MOVE_NUM = 2;

    public class Cell {

        public Cell(int row, int col, char stone) {
            stoneRow = row;
            stoneCol = col;
            gameStone = stone;
        }
        private final int stoneRow;
        private final int stoneCol;
        private char gameStone;
    }

    public ConnectFour(JFrame frame) {
        window = frame;
        playGame();
    }

    private void playGame() {

        game = true;
        playerNo = 0;
        player = true;
        winComputer = false;
        winPlayer = false;
        this.gameBoard = new ArrayList<>();
        gameBoardHeight = getHeightFromUser();
        gameBoardWidth = gameBoardHeight;
        playerOption = choosePlayer();
        buttons = new JButton[gameBoardHeight][gameBoardHeight];
        grid = new GridLayout(gameBoardHeight, gameBoardHeight);
        setLayout(grid);
        initializeButtons();
        revalidate();
        repaint();
        initalGameBoard();
    }

    private void initializeButtons() {
        int text_size = 0;
        if (gameBoardHeight > 3 && gameBoardHeight < 10) {
            text_size = 35;
        } else if (gameBoardHeight > 9 && gameBoardHeight < 15) {
            text_size = 25;
        } else if (gameBoardHeight < 19 && gameBoardHeight > 15) {
            text_size = 10;
        } else {
            text_size = 7;
        }
        for (int i = 0; i < gameBoardHeight; ++i) {
            for (int j = 0; j < gameBoardHeight; ++j) {
                buttons[i][j] = new JButton();
                buttons[i][j].setText("");
                buttons[i][j].setBackground(Color.DARK_GRAY);
                buttons[i][j].setForeground(Color.BLACK);
                buttons[i][j].setFont(new Font("Bukhari", Font.BOLD, text_size));
                buttons[i][j].putClientProperty("row", i);
                buttons[i][j].putClientProperty("col", j);
                buttons[i][j].addActionListener(new buttonListener());
                add(buttons[i][j]);
            }
        }

    }

    private class buttonListener implements ActionListener {

        @Override
        public void actionPerformed(ActionEvent e) {
            int row = 0, col;
            JButton buttonClicked = (JButton) e.getSource();
            col = (int) buttonClicked.getClientProperty("col");
            if (playerOption == 'C' || playerOption == 'c') {
                tempTargetCol = col + DECIMAL_LOWER_A;
                playComputerUser();
                for (int i = 0; i < gameBoardHeight; ++i) {
                    for (int j = 0; j < gameBoardHeight; ++j) {
                        if (gameBoard.get(i).get(j).gameStone == 'X'
                                || gameBoard.get(i).get(j).gameStone == 'O') {

                            if (gameBoard.get(i).get(j).gameStone == 'X') {
                                buttons[i][j].setForeground(Color.green);
                            } else {
                                buttons[i][j].setForeground(Color.red);
                            }
                            String addElement = Character.toString(gameBoard.get(i).get(j).gameStone);
                            buttons[i][j].setText(addElement);
                        }
                    }
                    if (winComputer) {
                        String winner = "Computer won the game";
                        int n = JOptionPane.showConfirmDialog(window, "NEW GAME?", winner,
                                JOptionPane.YES_NO_OPTION);
                        if (n < 1) {
                            removeAll();
                            playGame();
                        } else {
                            window.dispose();
                        }
                    }
                    if (winPlayer) {
                        String winner = "You won the game";
                        int n = JOptionPane.showConfirmDialog(window, "NEW GAME?", winner,
                                JOptionPane.YES_NO_OPTION);
                        if (n < 1) {
                            removeAll();
                            playGame();
                        } else {
                            window.dispose();
                        }
                    }
                    if (checkEmptyArea() == false) {
                        String winner = "Game Board is Full";
                        int n = JOptionPane.showConfirmDialog(window, "NEW GAME?", winner,
                                JOptionPane.YES_NO_OPTION);
                        if (n < 1) {
                            removeAll();
                            playGame();
                        } else {
                            window.dispose();
                        }
                    }
                }
            } else if (playerOption == 'P' || playerOption == 'p') {
                tempTargetCol = col + DECIMAL_LOWER_A;
                playUser1User2();
                for (int i = 0; i < gameBoardHeight; ++i) {
                    if (gameBoard.get(i).get(col).gameStone != '.') {
                        ++row;
                    }
                }
                String addElement = Character.toString(userStone);
                if (userStone == 'X') {
                    buttons[gameBoardHeight - row][col].setForeground(Color.green);
                } else {
                    buttons[gameBoardHeight - row][col].setForeground(Color.red);
                }
                buttons[gameBoardHeight - row][col].setText(addElement);

                if (game == false && checkEmptyArea() == true) {
                    String winner = "Player " + playerNo + " won the game";
                    int n = JOptionPane.showConfirmDialog(window, "NEW GAME?", winner,
                            JOptionPane.YES_NO_OPTION);
                    if (n < 1) {
                        removeAll();
                        playGame();
                    } else {
                        window.dispose();
                    }
                }
                if (checkEmptyArea() == false) {
                    String winner = "Game Board is Full";
                    int n = JOptionPane.showConfirmDialog(window, "NEW GAME?", winner,
                            JOptionPane.YES_NO_OPTION);
                    if (n < 1) {
                        removeAll();
                        playGame();
                    } else {
                        window.dispose();
                    }
                }
            }
        }
    }

    /**
     * This function retrieves the height information of the game board from the
     * user and checks whether the size of the game board is wrong
     *
     * @return
     */
    private int getHeightFromUser() {
        String getHeight;
        int sizeFlag = 1, gameBoardHeight;
        do {
            getHeight = JOptionPane.showInputDialog("Enter game board size");
            gameBoardHeight = Integer.parseInt(getHeight);

            if (gameBoardHeight < MINIMUM_BOARD_HEIGHT) {
                JOptionPane.showMessageDialog(null,
                        "Board size must be greater than 4", "Board Size Error",
                        JOptionPane.PLAIN_MESSAGE);
            } else {
                sizeFlag = 0;
            }
        } while (sizeFlag == 1);
        return gameBoardHeight;
    }

    /**
     * This function asks the user whether the game will be played against
     * computer or against a player and checks error status
     *
     * @return
     */
    private char choosePlayer() {
        String getChoosePlayer;
        int playerFlag = 1;
        char playerOption;
        do {
            getChoosePlayer = JOptionPane.showInputDialog("Player vs Player      : P - p\nComputer vs Player: C - c");
            playerOption = getChoosePlayer.charAt(0);

            if (playerOption >= 'a' && playerOption <= 'z') {
                playerOption -= 32;
            }
            if (!(playerOption == 'C' || playerOption == 'P') ||getChoosePlayer.length()>1) {
                JOptionPane.showMessageDialog(null,
                        "Invalid player option", "Player Option Error",
                        JOptionPane.PLAIN_MESSAGE);
            } else {
                playerFlag = 0;
            }
        } while (playerFlag == 1);
        return playerOption;
    }

    /**
     * This function fills with the point character to show game board as empty
     */
    private void initalGameBoard() {
        for (int i = 0; i < gameBoardHeight; ++i) {
            ArrayList<Cell> tempCells = new ArrayList<>();
            for (int j = 0; j < gameBoardHeight; ++j) {
                Cell singleCell = new Cell(i, j, '.');
                tempCells.add(singleCell);
            }
            gameBoard.add(tempCells);
        }
    }

    /**
     * This function invokes the necessary functions for the game played against
     * the computer or player and starts the game
     */
    private void playUser1User2() {
        /**
         * If game variable is true, the game continues to play.If the game
         * board is full or one of the players wins, the game is over.
         */
        if (player) {
            userStone = 'X';
            playerNo = 1;
        }
        if (!player) {
            userStone = 'O';
            playerNo = 2;
        }
        //tempTargetCol = getPosition(checkCol);

        putStone(tempTargetCol);
        if (userStone == 'X') {
            player = false;

        } else {
            player = true;
        }
        /**
         * Check if there are any winners after each move
         */
        int numberDiagonal = checkDiagonal();
        int numberHorizontal = checkHorizontal();
        int numberVertical = checkVertical();
        if (numberDiagonal >= WINNING_NUMBER || numberHorizontal >= WINNING_NUMBER
                || numberVertical >= WINNING_NUMBER) {
            game = false;
        }
        if (game) {
            game = checkEmptyArea();
        }
    }

    /**
     * This function works when the game is played against the computer. First,
     * the player moves and then the computer moves. When the computer moves, it
     * tries to prevent the player from winning and makes logical moves
     */
    private void playComputerUser() {
        int randomMove = 1, stoneNumber = 0;
        boolean computer = false;
        computerMove = true;
        if (player) {
            userStone = 'X';
            putStone(tempTargetCol);
            /**
             * Check if there are any winners after each move
             */
            if (checkDiagonal() >= WINNING_NUMBER || checkHorizontal() >= WINNING_NUMBER
                    || checkVertical() >= WINNING_NUMBER) {
                game = false;
                winPlayer = true;
            }
            if (game) {
                game = checkEmptyArea();
            }
            player = false;
        }
        if (!player && game) {
            /**
             * According to the player's move, the computer makes a logical move
             */
            while (computerMove) {
                switch (randomMove) {
                    case 1:
                        userStone = 'X';
                        stoneNumber = checkHorizontal();
                        if (stoneNumber == 2) {
                            if (!checkValidColumn(tempTargetCol - 1, computer)
                                    && checkColumnCapasity(tempTargetCol - 1, computer)) {
                                userStone = 'O';
                                tempComputerMove = tempTargetCol - 1;
                                computerMove = computerStoneMove(tempComputerMove);
                            }
                        } else if (stoneNumber == 3) {
                            if (!checkValidColumn(tempTargetCol + 1, computer)
                                    && checkColumnCapasity(tempTargetCol + 1, computer)) {
                                userStone = 'O';
                                tempComputerMove = tempTargetCol + 1;
                                computerMove = computerStoneMove(tempComputerMove);
                            }
                        }
                        break;
                    case 2:
                        userStone = 'X';
                        stoneNumber = checkVertical();
                        if (stoneNumber == 2 || stoneNumber == 3) {
                            if (!checkValidColumn(tempTargetCol, computer)
                                    && checkColumnCapasity(tempTargetCol, computer)) {
                                userStone = 'O';
                                tempComputerMove = tempTargetCol;
                                computerMove = computerStoneMove(tempComputerMove);
                            }
                        }
                        break;
                    case 3:
                        userStone = 'X';
                        stoneNumber = checkDiagonal();
                        if (stoneNumber == 1 || stoneNumber == 2) {
                            if (!checkValidColumn(tempTargetCol + 1, computer)
                                    && checkColumnCapasity(tempTargetCol + 1, computer)) {
                                userStone = 'O';
                                tempComputerMove = tempTargetCol + 1;
                                computerMove = computerStoneMove(tempComputerMove);
                            }
                        }
                        if (stoneNumber == 3) {
                            if (!checkValidColumn(tempTargetCol - 1, computer)
                                    && checkColumnCapasity(tempTargetCol - 1, computer)) {
                                userStone = 'O';
                                tempComputerMove = tempTargetCol - 1;
                                computerMove = computerStoneMove(tempComputerMove);
                            }
                        }
                        break;
                    case 4:
                        tempTargetCol -= ARTIFICAL_MOVE_NUM;

                        if (tempTargetCol < DECIMAL_LOWER_A) {
                            tempTargetCol = DECIMAL_LOWER_A;

                        }
                        for (int i = 0; i < gameBoardWidth; i++) {
                            if (checkColumnCapasity(tempTargetCol, computer)) {
                                userStone = 'O';
                                tempComputerMove = tempTargetCol;
                                computerMove = computerStoneMove(tempComputerMove);
                                i = gameBoardWidth;
                            }
                            tempTargetCol += 1;
                            if (tempTargetCol > DECIMAL_LOWER_A + gameBoardWidth - 1) {
                                tempTargetCol = DECIMAL_LOWER_A;
                            }
                        }
                        break;
                }
                if (randomMove <= WINNING_NUMBER) {
                    ++randomMove;
                } else {
                    randomMove = 1;
                }
            }
            /**
             * Check if there are any winners after each move
             */
            if (checkDiagonal() >= WINNING_NUMBER || checkHorizontal() >= WINNING_NUMBER
                    || checkVertical() >= WINNING_NUMBER) {
                game = false;
                winPlayer = true;
            }
            if (game) {
                game = checkEmptyArea();
            }

            player = true;
        }
    }

    /**
     * This function checks whether there are four stones vertically
     */
    private int checkVertical() {
        int maxStone = 0, countStone = 0;
        for (int i = 0; i < gameBoardWidth; ++i) {
            for (int j = 0; j < gameBoardHeight; ++j) {
                if (gameBoard.get(j).get(i).gameStone == userStone) {

                    ++countStone;
                    /**
                     * Determine the number of the most repeated stones in the
                     * vertical
                     */
                    if (countStone > maxStone) {
                        maxStone = countStone;
                    }
                } else /**
                 * If the stone is not equal to player stone, reset number of
                 * countStone and store in column change
                 */
                {
                    countStone = 0;
                }
            }
            /**
             * Reset number of countStone and store in column change
             */
            countStone = 0;
        }
        return maxStone;
    }

    /**
     * This function checks whether there are four stones horizontally
     */
    private int checkHorizontal() {
        int maxStone = 0, countStone = 0;
        for (int i = 0; i < gameBoardHeight; ++i) {
            for (int j = 0; j < gameBoardWidth; ++j) {
                if (gameBoard.get(i).get(j).gameStone == userStone) {
                    ++countStone;
                    /**
                     * Determine the number of the most repeated stones in the
                     * horizontal
                     */
                    if (countStone > maxStone) {
                        maxStone = countStone;
                    }
                }/**
                 * If the stone is not equal to player stone, reset number of
                 * countStone and store in column change
                 */
                else {
                    countStone = 0;
                }
            }
            /**
             * Reset number of countStone and store in column change
             */
            countStone = 0;
        }
        return maxStone;
    }

    /**
     * This function checks whether there are four stones diagonally
     */
    private int checkDiagonal() {
        int col = 0, row = 0, tempRow = 0;
        int maxStone = 0, countStone = 0;
        int gameBoardSize = 0;
        if (gameBoardHeight > gameBoardWidth) {
            gameBoardSize = gameBoardHeight;
        } else {
            gameBoardSize = gameBoardWidth;
        }

        while (row < gameBoardSize) {
            while (row >= 0) {
                if (row < gameBoardHeight && col < gameBoardWidth) {
                    if (gameBoard.get(row).get(col).gameStone == userStone) {

                        ++countStone;
                        /**
                         * Determine the number of the most repeated stones in
                         * the diagonal
                         */
                        if (countStone > maxStone) {
                            maxStone = countStone;
                        }
                    } else {
                        /**
                         * If the stone is not equal to player stone, reset
                         * number of countStone and store in column change
                         */
                        countStone = 0;
                    }
                }
                --row;
                ++col;
            }
            ++tempRow;
            row = tempRow;
            col = 0;
            countStone = 0;
        }
        int tempCol = gameBoardSize - 1;
        row = gameBoardSize - 1;
        tempRow = gameBoardSize - 1;
        col = gameBoardSize - 1;

        while (col > 0) {
            while (col < gameBoardSize) {
                if (row < gameBoardHeight && col < gameBoardWidth) {
                    if (gameBoard.get(row).get(col).gameStone == userStone) {
                        ++countStone;
                        /**
                         * Determine the number of the most repeated stones in
                         * the diagonal
                         */
                        if (countStone > maxStone) {
                            maxStone = countStone;
                        }
                    } else {
                        /**
                         * If the stone is not equal to player stone, reset
                         * number of countStone and store in column change
                         */
                        countStone = 0;
                    }
                }
                --row;
                ++col;
            }
            --tempCol;
            col = tempCol;
            row = tempRow;
            countStone = 0;
        }
        col = gameBoardSize - 1;
        tempCol = gameBoardSize - 1;
        row = 0;

        while (col >= 0) {
            while (col < gameBoardSize) {
                if (row < gameBoardHeight && col < gameBoardWidth) {
                    if (gameBoard.get(row).get(col).gameStone == userStone) {
                        ++countStone;
                        /**
                         * Determine the number of the most repeated stones in
                         * the diagonal
                         */
                        if (countStone > maxStone) {
                            maxStone = countStone;
                        }
                    } else {
                        /**
                         * If the stone is not equal to player stone, reset
                         * number of countStone and store in column change
                         */
                        countStone = 0;
                    }
                }
                ++row;
                ++col;
            }
            --tempCol;
            col = tempCol;
            row = 0;
            countStone = 0;
        }
        row = gameBoardSize - 1;
        tempRow = gameBoardSize - 1;
        col = 0;

        while (row > 0) {
            while (row < gameBoardSize) {
                if (row < gameBoardHeight && col < gameBoardWidth) {
                    if (gameBoard.get(row).get(col).gameStone == userStone) {
                        ++countStone;
                        /**
                         * Determine the number of the most repeated stones in
                         * the diagonal
                         */
                        if (countStone > maxStone) {
                            maxStone = countStone;
                        }
                    } else {
                        /**
                         * If the stone is not equal to player stone, reset
                         * number of countStone and store in column change
                         */
                        countStone = 0;
                    }
                }
                ++row;
                ++col;
            }
            --tempRow;
            row = tempRow;
            col = 0;
            countStone = 0;
        }
        return maxStone;
    }

    /**
     * This function checks whether the game board is full
     */
    private boolean checkEmptyArea() {
        int fullBoard = 0;
        int totalIndex = gameBoardHeight * gameBoardWidth;
        for (int i = 0; i < gameBoardHeight; ++i) {
            for (int j = 0; j < gameBoardWidth; ++j) {
                if (gameBoard.get(i).get(j).gameStone != '.') {
                    ++fullBoard;
                }
            }
        }
        if (fullBoard == totalIndex) {
            System.out.println("Game Over Board Ground Full");
            return false;
        } else {
            return true;
        }
    }

    /**
     * This function checks whether the capacity of the column is full
     */
    private boolean checkColumnCapasity(int col, boolean computer) {
        boolean capacity = true;
        if (gameBoard.get(0).get(col - DECIMAL_LOWER_A).gameStone != '.') {
            if (computer == true) {
                System.err.println("Column capacity is full");
            }
            capacity = false;
        }
        return capacity;
    }

    /**
     * This function checks whether the capacity of the column is full
     */
    private boolean checkColumnCapasity(int col) {
        return checkColumnCapasity(col, true);
    }

    /**
     * This function checks whether the entered column information is within the
     * valid range of characters
     */
    boolean checkValidColumn(int column, boolean computer) {
        int tempLocation = DECIMAL_LOWER_A;
        int countSize = 0;
        boolean checkCol = true;
        for (int i = tempLocation; countSize < gameBoardWidth; ++i, ++countSize) {
            if (i == column) {
                checkCol = false;
            }
        }
        if (checkCol && computer == true) {
            System.err.println("Invalid target column");
        }
        return checkCol;
    }

    /**
     * This function checks whether the entered column information is within the
     * valid range of characters
     */
    boolean checkValidColumn(int column) {

        return checkValidColumn(column, true);
    }

    /**
     * This function puts a stone in the selected position by the computer
     */
    boolean computerStoneMove(int tempTargetCol) {
        putStone(tempTargetCol);
        return false;
    }

    /**
     * This function calculates the number of rows and places the stone at the
     * empty position in the column for player move
     */
    void putStone(int tempTargetCol) {
        int emptyArea = 0;
        for (int i = 0; i < gameBoardHeight; ++i) {
            if (gameBoard.get(i).get(tempTargetCol - DECIMAL_LOWER_A).gameStone == '.') {
                ++emptyArea;
            }
        }
        if (gameBoard.get(emptyArea - 1).get(tempTargetCol - DECIMAL_LOWER_A).gameStone == '.') {
            gameBoard.get(emptyArea - 1).get(tempTargetCol - DECIMAL_LOWER_A).gameStone = userStone;
        }
    }

    /**
     * This function retrieves the column information from the player and places
     * a stone in the empty space in that column.If the column is full or the
     * wrong column information is entered, it prompts the player to enter the
     * column again.
     */
    int getPosition(boolean checkCol) {
        char targetCol;
        Scanner input = new Scanner(System.in);
        int tempTargetCol = 0;
        do {
            System.out.println("Target Position: ");
            targetCol = input.next().charAt(0);
            /**
             * If entered string is single character, assign zero index string
             * to character variable
             */
            if (targetCol >= 'A' && targetCol <= 'Z') {
                tempTargetCol = targetCol;
                tempTargetCol += 32;
            } else {
                tempTargetCol = targetCol;
            }
            if (checkValidColumn(tempTargetCol) == false
                    && checkColumnCapasity(tempTargetCol) == true) {
                checkCol = false;
            }
        } while (checkCol);
        checkCol = true;
        return tempTargetCol;
    }
}
