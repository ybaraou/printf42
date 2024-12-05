#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


int main() {
    // Test format 'c' avec NULL
    char *str_null = NULL;
    int ret_printf = printf("Test 'c' avec NULL : %c\n", (char)NULL);  // Attendu : Test 'c' avec NULL : (comportement propre selon l'implémentation)
    int ret_ft_printf = ft_printf("Test 'c' avec NULL : %c\n", (char)NULL);  // Attendu : même comportement
    if (ret_printf != ret_ft_printf) {
        printf("!!!!!!!!!! Les retours diffèrent pour 'c' avec NULL\n");
    }

    // Test format 's' avec NULL
    ret_printf = printf("Test 's' avec NULL : %s\n", str_null);  // Attendu : Test 's' avec NULL : (null) ou équivalent
    ret_ft_printf = ft_printf("Test 's' avec NULL : %s\n", str_null);
    if (ret_printf != ret_ft_printf) {
        printf("!!!!!!!!!! Les retours diffèrent pour 's' avec NULL\n");
    }

    // Test format 'p' avec NULL
    ret_printf = printf("Test 'p' avec NULL : %p\n", str_null);  // Attendu : Test 'p' avec NULL : (nil) ou équivalent
    ret_ft_printf = ft_printf("Test 'p' avec NULL : %p\n", str_null);
    if (ret_printf != ret_ft_printf) {
        printf("!!!!!!!!!! Les retours diffèrent pour 'p' avec NULL\n");
    }

    // Test format 'd' avec NULL (convertir NULL à 0)
    ret_printf = printf("Test 'd' avec NULL : %d\n", (int)NULL);  // Attendu : Test 'd' avec NULL : 0
    ret_ft_printf = ft_printf("Test 'd' avec NULL : %d\n", (int)NULL);
    if (ret_printf != ret_ft_printf) {
        printf("!!!!!!!!!! Les retours diffèrent pour 'd' avec NULL\n");
    }

    // Test format 'i' avec NULL (convertir NULL à 0)
    ret_printf = printf("Test 'i' avec NULL : %i\n", (int)NULL);  // Attendu : Test 'i' avec NULL : 0
    ret_ft_printf = ft_printf("Test 'i' avec NULL : %i\n", (int)NULL);
    if (ret_printf != ret_ft_printf) {
        printf("!!!!!!!!!! Les retours diffèrent pour 'i' avec NULL\n");
    }

    // Test format 'u' avec NULL (convertir NULL à 0)
    ret_printf = printf("Test 'u' avec NULL : %u\n", (unsigned int)NULL);  // Attendu : Test 'u' avec NULL : 0
    ret_ft_printf = ft_printf("Test 'u' avec NULL : %u\n", (unsigned int)NULL);
    if (ret_printf != ret_ft_printf) {
        printf("!!!!!!!!!! Les retours diffèrent pour 'u' avec NULL\n");
    }

    // Test format 'x' avec NULL (convertir NULL à 0)
    ret_printf = printf("Test 'x' avec NULL : %x\n", (int)NULL);  // Attendu : Test 'x' avec NULL : 0
    ret_ft_printf = ft_printf("Test 'x' avec NULL : %x\n", (int)NULL);
    if (ret_printf != ret_ft_printf) {
        printf("!!!!!!!!!! Les retours diffèrent pour 'x' avec NULL\n");
    }

    // Test format 'X' avec NULL (convertir NULL à 0)
    ret_printf = printf("Test 'X' avec NULL : %X\n", (int)NULL);  // Attendu : Test 'X' avec NULL : 0
    ret_ft_printf = ft_printf("Test 'X' avec NULL : %X\n", (int)NULL);
    if (ret_printf != ret_ft_printf) {
        printf("!!!!!!!!!! Les retours diffèrent pour 'X' avec NULL\n");
    }

    // Test format '%' avec NULL (affiche juste un '%')
    ret_printf = printf("Test '%%' avec NULL : %%\n");  // Attendu : Test '%%' avec NULL : %
    ret_ft_printf = ft_printf("Test '%%' avec NULL : %%\n");
    if (ret_printf != ret_ft_printf) {
        printf("!!!!!!!!!! Les retours diffèrent pour '%%' avec NULL\n");
    }

     // Sauvegarder stdout avant de le fermer
    int saved_stdout = dup(STDOUT_FILENO);

    // Fermer stdout (file descriptor 1)
    close(STDOUT_FILENO);

    // Test avec stdout fermé (ne devrait rien afficher)
    ret_printf = printf("Ce message ne s'affichera pas.\n");
    ret_ft_printf = ft_printf("Ce message ne s'affichera pas.\n");
    if (ret_printf != ret_ft_printf) {
        printf("!!!!!!!!!! Les retours diffèrent après fermeture de stdout\n");
    }

    // Restaurer stdout
    dup2(saved_stdout, STDOUT_FILENO);
    close(saved_stdout);

    // Vérifier que stdout fonctionne à nouveau
    ret_printf = printf("Ce message s'affichera après restauration de stdout.\n");
    ret_ft_printf = ft_printf("Ce message s'affichera après restauration de stdout.\n");
    if (ret_printf != ret_ft_printf) {
        printf("!!!!!!!!!! Les retours diffèrent après restauration de stdout\n");
    }

    // Test format 'c' (character)
    char c = 'A';
    ret_printf = printf("Test 'c' : %c\n", c);  // Attendu : Test 'c' : A
    ret_ft_printf = ft_printf("Test 'c' : %c\n", c);
    if (ret_printf != ret_ft_printf) {
        printf("!!!!!!!!!! Les retours diffèrent pour 'c' : %c\n", c);
    }

    // Test format 's' (string)
    char *str = "Bonjour";
    ret_printf = printf("Test 's' : %s\n", str);  // Attendu : Test 's' : Bonjour
    ret_ft_printf = ft_printf("Test 's' : %s\n", str);
    if (ret_printf != ret_ft_printf) {
        printf("!!!!!!!!!! Les retours diffèrent pour 's' : %s\n", str);
    }

    // Test format 'p' (pointer)
    int x = 42;
    ret_printf = printf("Test 'p' : %p\n", &x);  // Attendu : Test 'p' : <adresse mémoire de x>
    ret_ft_printf = ft_printf("Test 'p' : %p\n", &x);
    if (ret_printf != ret_ft_printf) {
        printf("!!!!!!!!!! Les retours diffèrent pour 'p' : %p\n", &x);
    }

    // Test format 'd' (signed integer)
    int n = -123;
    ret_printf = printf("Test 'd' : %d\n", n);  // Attendu : Test 'd' : -123
    ret_ft_printf = ft_printf("Test 'd' : %d\n", n);
    if (ret_printf != ret_ft_printf) {
        printf("!!!!!!!!!! Les retours diffèrent pour 'd' : %d\n", n);
    }

    // Test format 'i' (signed integer, identique à d)
    ret_printf = printf("Test 'i' : %i\n", n);  // Attendu : Test 'i' : -123
    ret_ft_printf = ft_printf("Test 'i' : %i\n", n);
    if (ret_printf != ret_ft_printf) {
        printf("!!!!!!!!!! Les retours diffèrent pour 'i' : %i\n", n);
    }

    // Test format 'u' (unsigned integer)
    unsigned int u = 123;
    ret_printf = printf("Test 'u' : %u\n", u);  // Attendu : Test 'u' : 123
    ret_ft_printf = ft_printf("Test 'u' : %u\n", u);
    if (ret_printf != ret_ft_printf) {
        printf("!!!!!!!!!! Les retours diffèrent pour 'u' : %u\n", u);
    }

    // Test format 'x' (hexadecimal en minuscule)
    int hex = 255;
    ret_printf = printf("Test 'x' : %x\n", hex);  // Attendu : Test 'x' : ff
    ret_ft_printf = ft_printf("Test 'x' : %x\n", hex);
    if (ret_printf != ret_ft_printf) {
        printf("!!!!!!!!!! Les retours diffèrent pour 'x' : %x\n", hex);
    }

    // Test format 'X' (hexadecimal en majuscule)
    ret_printf = printf("Test 'X' : %X\n", hex);  // Attendu : Test 'X' : FF
    ret_ft_printf = ft_printf("Test 'X' : %X\n", hex);
    if (ret_printf != ret_ft_printf) {
        printf("!!!!!!!!!! Les retours diffèrent pour 'X' : %X\n", hex);
    }

    // Test format '%' (pour afficher le caractère '%')
    ret_printf = printf("Test '%%' : %%\n");  // Attendu : Test '%%' : %
    ret_ft_printf = ft_printf("Test '%%' : %%\n");
    if (ret_printf != ret_ft_printf) {
        printf("!!!!!!!!!! Les retours diffèrent pour '%%'\n");
    }

    ret_printf =  printf(NULL, 5, 10);
    ret_ft_printf = ft_printf(NULL, 5, 10);
     if (ret_printf != ret_ft_printf) {
        printf("!!!!!!!!!! Les retours diffèrent pour NULL, 5, 10==printf===%d===ft_printf====%d\n", ret_printf, ret_ft_printf);
    }

     ret_printf =  printf(NULL);
    ret_ft_printf = ft_printf(NULL);
     if (ret_printf != ret_ft_printf) {
        printf("!!!!!!!!!! Les retours diffèrent pour NULL===== printf===%d======ft_printf====%d\n", ret_printf, ret_ft_printf);
    }

    // Test avec printf avant la fermeture de stdout
    printf("Test avant close(1) - printf\n");  // Cela devrait afficher et retourner le nombre de caractères imprimés
    ret_printf = printf("Test avant close(1) - printf\n");
    printf("Valeur retour de printf: %d\n", ret_printf);  // Affiche le retour de printf

    // Test avec ft_printf avant la fermeture de stdout
    ft_printf("Test avant close(1) - ft_printf\n");  // Cela devrait afficher et retourner le nombre de caractères imprimés
    ret_ft_printf = ft_printf("Test avant close(1) - printf\n");
    printf("Valeur retour de ft_printf: %d\n", ret_ft_printf);  // Affiche le retour de ft_printf

    // Fermer stdout
    close(1);

    // Test avec printf après la fermeture de stdout
    ret_printf = printf("Test après close(1) - printf\n");  // Ne devrait pas afficher, mais retourne peut-être un nombre de caractères
    printf("Valeur retour de printf après close(1): %d\n", ret_printf);

    // Test avec ft_printf après la fermeture de stdout
    ret_ft_printf = ft_printf("Test après close(1) - printf\n");  // Ne devrait pas afficher, mais retourne peut-être un nombre de caractères
    printf("Valeur retour de ft_printf après close(1): %d\n", ret_ft_printf);

    // Réouvrir stdout
    freopen("/dev/tty", "w", stdout);

    printf("Valeur de retour, printf===%d===ft_printf===%d== \n", ret_printf, ret_ft_printf);
    // Test avec printf après réouverture de stdout
    ret_printf = printf("Test après réouverture de stdout - printf\n");  // Cela devrait afficher et retourner le nombre de caractères imprimés
    printf("Valeur retour de printf après réouverture: %d\n", ret_printf);

    // Test avec ft_printf après réouverture de stdout
    ret_ft_printf = ft_printf("Test après réouverture de stdout - printf\n");  // Cela devrait afficher et retourner le nombre de caractères imprimés
    printf("Valeur retour de ft_printf après réouverture: %d\n", ret_ft_printf);

    return 0;
}

