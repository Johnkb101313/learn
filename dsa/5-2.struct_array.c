/* face 1-K == 1-13*/
/* shape 1, 2, 3, 4*/
/* colour 0 == red & 1 == black*/
struct Card
{
    int face;
    int shape;
    int colour;
};

int main()
{
    struct Card deck[52] = {{1,1,0}, {1,2,0}, {1,3,0}, {1,4,0},
                            {1,1,1}, {1,2,1}, {1,3,1}, {1,4,1}};

    return 0;
}
