#include <stdio.h>
int main(){
    int x;
    scanf("%d",&x);

    int kategori;
    if(x <= 10) kategori = x + 1;
    else kategori = (x - 10) + 11;
    if(kategori < 1) kategori = 1;
    if(kategori > 40) kategori = 40;

    printf("Title Asep\n");
    printf("Roasting Mas Agus\n");

    switch(kategori){
        case 1: printf("Wah bocah baru nih! Masih cupu banget dah!\n"); break;
        case 2: printf("Lumayan lah, udah mulai keliatan bakatnya dikit!\n"); break;
        case 3: printf("Oke sih, tapi masih jauh dari kata jago!\n"); break;
        case 4: printf("Mulai rame nih gameplaynya, mantul!\n"); break;
        case 5: printf("Asik banget! Udah mulai pede main bareng!\n"); break;
        case 6: printf("Anjay mabar! Udah bisa ngebawa tim nih!\n"); break;
        case 7: printf("Wahh gokil! Udah mulai bikin lawan ketar-ketir!\n"); break;
        case 8: printf("Jago banget! Respect dah!\n"); break;
        case 9: printf("Gila bener! Udah hampir level dewa nih!\n"); break;
        case 10: printf("Anjir keren! Skill udah mulai mencla-mencle!\n"); break;
        case 11: printf("Waduh sultan! Udah masuk zona berbahaya!\n"); break;
        case 12: printf("Gokil parah! Lawan udah pada ngacir semua!\n"); break;
        case 13: printf("GILAAAA ! Bikin musuh pada salty!\n"); break;
        case 14: printf("Asli gila! Main kek orang kesurupan!\n"); break;
        case 15: printf("Anjay sultan! Duit orang tua abis buat warnet!\n"); break;
        case 16: printf("Waduh bocil! Udah kecanduan berat nih!\n"); break;
        case 17: printf("Gokil memang! Mata udah sipit gara-gara main!\n"); break;
        case 18: printf("GILA BANGET! Makan minum lupa gara-gara game!\n"); break;
        case 19: printf("Asli dewa! Udah level dukun gaming!\n"); break;
        case 20: printf("Anjir legend! Warnet jadi rumah kedua!\n"); break;
        case 21: printf("Waduh pak bos! Udah jadi langganan warnet!\n"); break;
        case 22: printf("Gokil abis! Kursi warnet udah ada bekas pantatmu!\n"); break;
        case 23: printf("Halo Pengabdi ! Mas warnet udah kenal keluarga!\n"); break;
        case 24: printf("Asli Gila! 24 jam di warnet terus!\n"); break;
        case 25: printf("Anjay bocil! Pegang mouse udah kek pegangan motor!\n"); break;
        case 26: printf("Waduh bro! Keyboard udah aus gara-gara lu!\n"); break;
        case 27: printf("Gokil banget! Headset udah jadi mahkota!\n"); break;
        case 28: printf("Capek gw! Warnet tutup aja gara-gara lu!\n"); break;
        case 29: printf("Asli gila! Mimpi juga main game terus!\n"); break;
        case 30: printf("Anjir dewa! Udah jadi furniture warnet!\n"); break;
        case 31: printf("Waduh sultan gaming! Udah punya kursi sendiri!\n"); break;
        case 32: printf("Gokil emperor! Mas warnet udah jadi sahabat!\n"); break;
        case 33: printf("ANJAY legend! Warnet udah kayak rumah sendiri!\n"); break;
        case 34: printf("Asli mythic! Tagihan warnet udah kek tagihan listrik!\n"); break;
        case 35: printf("Anjay immortal! Keluarga udah lupain muka lu!\n"); break;
        case 36: printf("Waduh radiant! Tetangga udah bosen nyariin lu!\n"); break;
        case 37: printf("Gokil valorant! Guru udah nyerah ngajarin lu!\n"); break;
        case 38: printf("ANJAY conqueror! Polisi udah tau tempat lu!\n"); break;
        case 39: printf("Asli grandmaster! Presiden udah tau nama lu!\n"); break;
        case 40: printf("ANJAY BOCAH WARNET SEJATI! LU UDAH JADI LEGENDA!\n"); break;
    }
    return 0;
}