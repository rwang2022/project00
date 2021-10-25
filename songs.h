
#define TITLE_SIZE 100
#define ARTIST_SIZE 100

struct song_node
{
    char title[TITLE_SIZE];
    char artist[ARTIST_SIZE];
    struct song_node* next;
};


struct song_node* free_list(struct song_node* s);

struct song_node* create_node(char* t, char* a);

void print_song(struct song_node* s);

void print_list(struct song_node* s);

struct song_node* insert_front(struct song_node* s, char* t, char* a);

int song_cmp(struct song_node* a, struct song_node* b);

struct song_node* insert_ordered(struct song_node* s, char* t, char* a);

struct song_node* find_node_given_info(struct song_node* s, char* t, char* a);

struct song_node* find_artist_first(struct song_node* s, char* artist);

struct song_node* random_node(struct song_node* front);

struct song_node* remove_node(struct song_node* front, char* t, char* a);
