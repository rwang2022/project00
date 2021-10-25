struct song_node**  create_library();

struct song_node**  add_song_node(struct song_node** library, char *title, char *artist);

struct song_node * find_song_in_library(struct song_node** library, char *title, char *artist);

struct song_node * find_artist_first_library(struct song_node** library, char *artist);

void print_letter(struct song_node** library, char letter);

void print_artist(struct song_node** library, char *artist);

void print_library(struct song_node** library);

void shuffle_library(struct song_node** library, int num_songs);

struct song_node**  delete_song(struct song_node** library, char *title, char *artist);

struct song_node**  clear_library(struct song_node** library);

int artistIndex(char *artist);

int charIndex(char c);
