# tic_tac_toe_self_learning
A learning experience; tic tac toe program in C

(check the wiki for animated gifs)

The design is set up thusly to accommodate easy plugin of new versions
and includes a human interface to test skill against..

All clients can be told to battle against each other.

The design is a typical client server setup, where the server mandates
the rules, keeps score, assigns players etc. The clients battle each other, 
deploy intelligence and talk to the server using a predefined protocol during 
gameplay.

This repo will contain multiple versions of clients, including a self learning
entity, but also a simpler minimax implementation.

Currently Done:
- Game keeper (server)
- Client for biological entities
- AI client employing random moves
- AI Minimax implementation (non optimized)

Todo:
- FANN self learning client
- Other ANN frameworks possibly

<img src="https://www.geenbs.nl/gifs/MinimaxVSRandom.gif">
