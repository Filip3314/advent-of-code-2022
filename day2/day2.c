#include <stdio.h>
typedef enum RockPaperScissors {
    ROCK=1,
    PAPER=2,
    SCISSORS=3
} RockPaperScissors_t;
typedef enum WinLoseDraw {WIN, LOSE, DRAW} WinLoseDraw_t;

int calc_rock_paper_scissors_score(RockPaperScissors_t their_choice, RockPaperScissors_t my_choice) {
    int outcome=0;
    if(my_choice == their_choice) { 
        outcome = 3;
    }
    else if((my_choice == ROCK && their_choice == SCISSORS) ||
            (my_choice == PAPER && their_choice == ROCK) ||
            (my_choice == SCISSORS && their_choice == PAPER)) {
        outcome = 6;
    }
    return my_choice + outcome;
}

RockPaperScissors_t translate_char_to_rps(char character) {
    if (character == 'A' || character == 'X') {
        return ROCK;
    }
    else if (character == 'B' || character == 'Y') {
        return PAPER;
    }
    else if (character == 'C' || character == 'Z') {
        return SCISSORS;
    }
    else {
        return -1;
    }
} 

RockPaperScissors_t choose_play_for_outcome(RockPaperScissors_t opponent_play, WinLoseDraw_t outcome) {
    if(outcome == WIN) {
        if(opponent_play == ROCK){
            return PAPER;
        }
        else if(opponent_play == PAPER) {
            return SCISSORS;
        }
        else return ROCK;
    }
    else if(outcome == LOSE) {
        if(opponent_play == ROCK){
            return SCISSORS;
        }
        else if(opponent_play == PAPER) {
            return ROCK;
        }
        else return PAPER;
    }
    return opponent_play;

}

WinLoseDraw_t translate_char_to_outcome(char character) {
    if(character == 'X') {
        return LOSE;
    }
    else if(character == 'Y') {
        return DRAW;
    }
    else if(character == 'Z') {
        return WIN;
    }
    return -1;
}
int main(int argc, char *argv[]) {
    FILE *in = fopen("input.txt", "r");
    char line[5];
    int part1_total_score = 0; 
    int part2_total_score = 0; 
    while(fgets(line, 5, in) != NULL) {
        RockPaperScissors_t opponent_play = translate_char_to_rps(line[0]);
        part1_total_score += calc_rock_paper_scissors_score(
                opponent_play, translate_char_to_rps(line[2]));
        part2_total_score += calc_rock_paper_scissors_score(
                opponent_play,
                choose_play_for_outcome(opponent_play, translate_char_to_outcome(line[2])));
    }
    printf("Total Score, assuming XYZ correspond to Rock/Paper/Scissor: %d\n", part1_total_score);
    printf("Total Score, assuming XYZ correspond to Lose/Draw/Win: %d\n", part2_total_score);
    fclose(in);
    return 0;
}
