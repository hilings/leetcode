//
//  336.cpp
//  leetcode
//
//  Created by Hang Zhang on 12/7/16.
//  Copyright © 2016 Hilings Studio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
    bool isPalindrome(string &s) {
        for (int i = 0, j = s.size()-1; i < j;) {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }
public:
    vector<vector<int>> palindromePairs0(vector<string>& words) {
        vector<vector<int>> vv;
        for (int i = 0; i < words.size()-1; i++) {
            for (int j = i+1; j < words.size(); j++) {
                string tmp = words[i]+words[j];
                if (isPalindrome(tmp))
                    vv.push_back(vector<int> {i, j});
                tmp = words[j]+words[i];
                if (isPalindrome(tmp))
                    vv.push_back(vector<int> {j, i});
            }
        }
        return vv;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> vv;
        unordered_map<string,int> m;
        for (int i = 0; i < words.size(); i++) {
            m[words[i]] = i;
        }
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j <= words[i].size(); j++) {
                string t1 = words[i].substr(0, j);
                string t2 = words[i].substr(j);
                if (isPalindrome(t1)) {
                    string tmp = t2;
                    reverse(tmp.begin(), tmp.end());
                    if (m.find(tmp) != m.end() && m[tmp] != i) {
                        vv.push_back(vector<int> {m[tmp], i});
                    }
                }
                if (j < words[i].size() && isPalindrome(t2)) {
                    string tmp = t1;
                    reverse(tmp.begin(), tmp.end());
                    if (m.find(tmp) != m.end() && m[tmp] != i) {
                        vv.push_back(vector<int> {i, m[tmp]});
                    }
                }
            }
        }
        return vv;
    }
};

int main(int arg, char *argv[]) {
    // insert code here...
    cout << "LeetCode 336. Palindrome Pairs, C++ ...\n\n";
    Solution sol;

    vector<string> words {
        //"bat", "tab", "cat"	// [[0, 1], [1, 0]]
        "abcd", "dcba", "lls", "s", "sssll"	// [[0, 1], [1, 0], [3, 2], [2, 4]]

        //"fhhffbebghdddiff","ahjbihicdicb","ehgdieggfefgaddgejcf","eicjjcbeedhe","bdabceihdh","jaad","ghedccf","fe","fcdjccagbccgaiae","cfjagghgiba","jehe","ch","ggadgg","ccjccfffdjgdibef","cahhjcfafbcg","eehdbc","aa","dadgj","jjjjehih","jiabjaafejdfigjdg","cbdh","habcjhfffcabidah","aeah","bjhbhajeh","jehihbfbdbcgdjdbega","hghffabjidfgjcj","afiihfegdac","ecchjadbaif","biadfacfedjgcjfeaeeh","b","hfghaiejdedgcag","ahdaagcjc","jdgdfcaeggbaecdbc","eajhcebbfabeefb","geeejii","cdbefgb","dbjhca","bfdhebhecg","ea","d","ddhjf","ach","dfejfachajfjf","cgjdijahfdfbj","gh","gegbcbjhfh","hjehffb","f","begaehdcdeed","hcjga","cajgd","chhbhfhijbhcejjbdjbh","fjgcf","hjjjfejgggihe","ejjjabcebh","jgcebedjdiijdghj","idbacgghbacjeiifj","abejcbfigijdgdjedcc","jjjfbchigcegffhdac","cea","jiigibjf","acdie","agdcajbba","gedbedfjehfbbaie","dfbghjggb","di","afccbdjie","hbaihh","ecbahegecffhcicajiaa","ccbcdeedfe","eicjigbabfjeg","j","gcacdcbafiajcdhff","jje","dacgffdhijiaebbaf","bbcg","bcdceegg","dafgcbbiejdghdggf","jifb","dcfdhabgiceffgeia","dbiebccagfjcabiahea","dahg","jjbce","ddiabfcc","ecededaghbadieecifie","agcjihifbjhggj","idib","jbcdbicgbijgbecdcjdf","edjheajfddbdjecdgjcc","jdgfijb","bdicehcae","bidaece","jifhgia","hjeihaecfgbhbgdd","gjj","djjgihhfbgba","eagghidchdjiedddccee","fghceajcge","jdhheeegghjijjcb","cbbbhhifhe","ijgjfjjibjdhf","jcbeebbifdcbgcjdj","feifaicf","idceadifheibgia","fgcfajeag","jfggfeaeeiihfbicd","bigiehgcbhfbghhccbf","biijjigf","affgaegbejfcbggac","gaibaceicdhjdbheejg","fieab","g","fhffeicjaedbeiagd","eibg","gfb","he","idijfc","cfib","baehdhjehgbbghb","bjfgdjd","fiecdjhfhhdihihgaege","fbgjdcggbeb","jcdjbchgbchcgb","ecegacheejgjgffjheg","cdfdibiachdiag","bicjaed","fjfeegab","iahajbefebefj","ebjejigieedjegbhag","jhhcifijdjgfgdii","fdfedabiicg","ajh","cjafaaddefiecaiih","bb","efdeicecafdehfeehgje","hhciejab","hggiahdegfdaj","bcaehfaa","jgeajhgihifcifbga","edag","ieehacagjbijib","ichhfebiefijdjfdf","jejc","jhcdb","cbjageidfajfjfcbggah","hddgecjddagaje","dffcjbiib","fejdbgdhejahjcfaggb","hfgajjedicedhcee","gdihjegg","ijbhfejjahdbajcbf","beaiigacdiicahgiig","aed","ehidhcf","eaehagedbfciihj","baacigefjaf","jciaieahg","idichajfahjfehbdgf","hcahg","h","edbihgfgechehcdb","gijabhbdedcjddhjihd","ehibabbh","ejcjbcjjiicbejfdcc","cjfiaegbeibjbaiifd","eaahbga","chcggghfgacejdjfhgg","jbjaaigjbjbhdh","hfddehabf","edad","dabhaghjiciji","gbiijcjabihgijcghhg","bcifahfed","dgdhbhbbccjciffjdae","jdaihi","jh","dc","jgfadajbafhdigbef","bjbgagfgcgbdgceagf","ebigf","fbbgbjcdbjbifbjc","fefjbc","edjjba","dbbjbefbcdgbfca","af","chf","gijbfjfdbj","egefhfci","fbgbjbgb","ebfjhgefdgdca","jbehjgebbda","eibhdejhfidhfdfa","jjhgjfbjhjehihcahb","haggjjfagibegeiiej","hdchic","ebdfijigie","hjddjcfciihdcfjjcf","hihec","ehbiffdiihhfg","iabfgcjhfcfhdjc","biddjjhbhahfdbdgcegi","fdadj","jdjecidejb","figaghhhdehgigfgbhc","jicfddgcjeedddge","ejiiijdjciebhjdgeiai","hiaeefbjf","fiefihddcejbbc","efhdf","diajdf","gebjdfeidch","gcgcecedbffeiea","fichj","cbcgab","je","efijhfgcgee","jcdhajhbgi","cfjghgc","bbhggggidbbffegbgac","hiifd","jegfahdhaiegbfi","ebahi","fififjaa","djbghfagbgafbddfejgc","iehjecjcgdcdfajgagih","gfhjgaigdeebifeb","hfdfaaddeba","ijhhaajdheaddabgfea","ebgfcacdhehafabfdb","e","ba","dageabbacjh","iccc","iagedbi","ichbgeafbaid","aeeghhafhjbej","iac","ceijfhci","ghhahajcj","dhcaecgcgc","ia","ebdcciacadgjdbefgg","ebdiffigdhbfgjhdeaca","hbhhidjgeacjcij","cbcc","giahgeejgcdihheie","jefc","caababdh","bgbhbccbbbgjgdhfcd","ehhaeeiegjcjjgdg","a","dfjjbbj","fchi","aedabbchididi","ajfiidhjfahfaedc","ggiejacjeccegid","fjab","fdehcaehhcfbhf","iddhbhfdbjdj","jcija","jdch","iehgfgdcieaiaibfh","egffddciffhhgejj","eh","jicbehffi","bgacjgege","dcgefjacdfaiciaa","jbg","ddhahhcbiffaciaied","efaehhagjfheeggb","fgda","jdjfhfagcbeag","affcfaaddic","gf","cihfibbbaejjja","bgibgdhgfdhdaeibeji","haidadafdchjihjibg","eedbehbgfdgc","hijdhfhff","ad","eeifhhbfbcaebh","fhfa","aihg","ciafibahj","dfgdifbheaai","bddhih","idfgda","cjghcbejbafdgb","ehjjgchhdh","eejeb","ijccdea","jhfbebci","ddjgieice","icdjaejcjdagedecbecb","fdegiehagcbcg","djidafihhfbeagicdci","egbfhafdagfddfa","iebhjefjcbfgd","eihfcdcgd","fdddjbcfhja","idjgbeddf","cediceic","gjehcahfhafbibajbd","djdaegagcig","gdajffjhjajchdidfc","cgjfidd","aeajjacdhdh","i","fa","dihhbbdajd","fdggifehada","fgbdidcabg","jhdchb","ajddbdjbci","bcidiedhehechcjfc","aifagabjbgdedaf","cegegcie","dhedji","fhaadbebchde","gbccfccefhcdf","hbjaec","jjjjaaij","dheihjbjicebjga","dcbca","bhfifhbbhgjgjifh","hibggbdbhafibhaed","edfidcaif","ai","ehiddghdhjeiedafagb","fgijccga","aibbcjcbjecgdfj","gaabgchde","fdfhhhefdejfbbje","hjjjeggfbijiafhceci","ieiddfcihgjbjideaef","bceaadejh","hdfcgbcjcabed","hihefjehhbhbde","ceigijcidiebbdb","gjihibdejdhc","cdagdhhjag","gadehjfedfgbbech","chh","jeafacahcagdhbi","ijiffjdfafadbajcae","hjheecgcja","hgfhbi","gdbibjhieffcaad","ie","heecigi","aii","cicaheiefeg","cabgiheiegchbaffd","baibj","fbheehadifchbbgge","hgecdbcdj","dhdafjbfcjcadc","hbfig","cgjfcde","gihfgdhadjgcf","ejgfaa","jf","jggh","jhgahggbgf","jifg","hjieaafiefbcheiahgg","gc","jdbdajjgaigjeb","jdjjhgfjb","jdhdijjihifbdfdejbc","aigbhegifcfi","iicgbiaffchedc","adfjafbi","jeejbdijhbeeab","cb","bibjjhjaifhfjhf","bbe","jgdfjdjh","dicdjdchecihhgciafg","eaigdcaifgha","hhjgbdegbdeaa","gjacggegfgdjchdg","iifa","dbbbefdicfcdj","haj","hffic","ceafj","ciffcigdhecbbjafeig","hdagch","eafhafeidhga","ebhidaei","jghijfbdgghcicbebcii","ifiahegdbghje","gccjgefcicadbcicdb","ibfag","bcehdcbjf","jjacieb","baeddecgfejjdfgib","fefjcggffhe","egaihgfjagf","cjjffcgcfidedeeh","deidj","cijbcfd","cc","cjbeedbdad","hiagdbi","ifejheifhajfbgcbh","ddjiggcedfaiicjbejeh","dbecgfjjjh","bhfhcgbbd","cg","cicbggdhg","bffjbdfhgfj","icafafah","hjacdd","ibfbiije","bfgbhdj","egica","abdcjefadhadcegcbace","cfhbjfadcafiabaded","fgcccafechffaecach","efbci","aeddcc","fb","aiddb","giieghegcgfacjf","fbbbcdag","jeebgaciggijdcc","fficgjfdjecjg","ijaeecbjgg","jiicjbhcijhebiaffhi","ifhbaghgebghiieidhd","fhjcjjbicedbf","cadcigigibg","dbihhc","fijajfdaffghhjidddd","jbgiccdcidhidddfhj","ehfgdeaagfcajiihcg","gedeab","bibfdbijhcaaj","db","eheh","ahbeafjfde","heibggeiibidbj","dajcgdga","hbgb","fjiahjhfgcaibfjehh","jdbcdgjjceihceg","dih","fbj","fjiheaffffbdcdfh","gjafeeigjicjfci","bad","ageaed","hbedbjdi","dafdadfacchbadagbf","biijebbfiebgbagcdbj","cdfajdgahhfiabihja","dbafbahegd","ehd","dhjeedfegi","fbicdjdhahebiijcjig","ieagijcbg","jhhg","hejefcebhhjahhbeh","ghafhejecgfbhbhdei","c","gggcibjcgjjghcdgj","gigcidjbif","ihjidcehghbc","hbidagbe","dgdhbdj","cihajhgbccegd","jdacejeadaejchj","acchaihghbaebdi","heebgieb","eadehddjiche","fjejehjdgejficdid","egaecdfdbfdjfc","gfccgbdciiijiaagifb","jhcedajifhi","ihcihj","gef","jhjah","bjfejhcjbjefgdce","ddaijf","iejc","hdhdcijhihjde","djajbgbhgajahdadgae","fifedh","cejhbfdegdefif","ddajbgici","dbgjbicgaagbaahcd","eeighagcadjab","cjhjdhi","bjejacfahdgajabff","jeih","jcbgifbgihdfdhbgffij","cjedf","eiefaffcjjgieccah","effeeiecchjda","ebejjgbcccbd","ahdihcegijhjcaidcacj","jbifdfefgh","fceagacdec","ghgf","aahcgaebihahajbjbga","abgbiiaecddbh","hjifajddfafggifggc","cihgbcdcje","gabiafjhdgc","cfee","fiaibggfj","eejebdedjjgbdea","giicaadefiigaieebeif","cagdficd","ifeehgfebffjdjec","gaifacejhgaejgfdabci","eaibddgbafiddhcd","ifdahajh","dad","gdafaehfdfdfcccajba","afdicig","dcjijhg","ihjcejjdjeb","ab","ffefdhdjgadehfjef","gjecjghefaidhgjb","ifjgihheafbbdibgeb","ghagigjhggbbdg","cigbiecafbee","hg","fcedjhfb","bhegjahbfibhgaeiee","edbeaaaabfigaicaihc","ecfbibi","cdabii","hhccebdijcebhaej","aiidhdfgibabgehf","bg","caaeagajacjcfj","ejjfbiff","gjibjjdejga","ifdafbbbehafgebia","bdfdigdebdifjccca","hgghfhc","dbeg","cggdcjfebgbc","hbdcabeeje","bhebcfi","hjdcdbfhffajea","ieifcahic","fbjf","ifdbbiabhhj","cfhj","gbicdjfdjjjheaedc","edbbhhjchgjcchjh","bjbcejafi","gbfefjcjieehee","aididgf","chgieiidjhbhd","aijigbeigfcdeadidba","iifacgafiiadafbdefgb","gjjbhcje","fhaeahdhcgbdg","ccadabjjeibfhgifd","cfhheeeecffbgibagff","hjgabbgeegb","aebi","gddgcge","cdbjjbhceiagbja","aahgieicjdbifjdgaha","dgeie","jgeihgeeijhecjhd","bfagddadg","aaeabhdiga","faeecdfebia","ifbii","hfchcfhgahdhgc","gefjjjbfcjjh","gecdifjbb","bhidbjf","jihbfgbghfdaifh","gfjjdeifbbgijc","jj","aga","bgdgbijbaibhigjga","cidc","eibda","fdieibeafcdibiiibhcf","aifhbghj","hahajebejc","daaffhjf","agehcfhbggf","jdfaffbachebgfihi","eagefh","agfdbhdidhhighbaieic","jaebbdcaahbgah","cjijggdfdcijdigg","iagjghbifchceedcddig","ciegjijaigchabf","feiiddaib","diddbjdidcgcjiggj","hejchdii","bcfddjfgdahghdabie","ejhdjggd","jijigjehfdabiei","egefifigbebedciebgg","hdcccgecafafcihjbgg","abi","ihfjbiajagbeifjedgg","jicdifjh","cdiaicgajbbjjbfeaebe","cicjegahefghfgbgdi","hgfahiaeabfief","hgfffabhhhbgh","edeccjfcbhgd","ecbecdhdgaejieaij","fjig","idbafcibechiheibih","fihffghajhdfechbadij","fdfjbebehi","bgejgfbhaidjhebadfij","hdfhejcabafdiagbbb","gcigagahaffifaeagdig","fiafihiddf","gjjciifibf","jahffhhfhedageb","fbhdjeccjeigahfhhb","jgcgebjdbgfd","fecjgeagggadcaedgdea","igcbahagjbbcahaifah","fjh","gjfchfhiajbc","bhibhiaiafdg","bfiadehbjfi","dahhfabcbaidcgcd","dggcbfbcghhj","ibicjjedabfi","hdec","gaggda","bied","djecejdeaea","iib","cbhihcjfdhgfbh","jjddhicjaedfeiejca","hjiigfidaabfiia","dhjhegagcjjigc","ahbfgcei","bjcibcichebjcagf","iggbfdfagcahgejbhedj","bcbdjbcjdjfbge","djfidbdeh","dibij","egdhjfd","bfjecfieafde","eific","cdchehci","gjgcfccjghdfjhfhfh","jjfbjgbccdjbjfhfci","iijajce","bfcibfgeibd","ajjhcjibhei","haiighajie","bhcdddai","eghhiddfjbdfhhffbhig","ifhaaeciec","jefjjf","ejcabfbaijadhbbec","iiij","iiddfdhbbbhed","aeig","bidjhddgbbfii","ej","jeidjfgjcb","jhbdgb","cijbbgihbdifcbgdhha","jfbgiiebfgbjh","dajegbfdibeacghbda","hiihehadicgd","cgieiacfieihjddc","ehdhdihbigfc","iigcgjegchggfa","ffcf","fjgcbcffccg","cfeddiffeejjdcfcb","ihe","cijbfeeccd","gbfagjaadcbbedfh","ege","bhfeeda","jbijgidfaiifif","eefehgghjadfb","achbdgeibgfffafajdhd","fbddhhiijbccda","gdeegaed","cggfj","djaa","cbghhbdh","agdhgbdacc","ihjbdicajgeaghee","hjaaigeeefjcf","gih","dhgehaeggfffhddihaa","cahgjdcjejfbefhfcg","hhgcecgcfj","aehhe","chjhcfafggjb","aia","bfcghccc","gdfiefjidhibdh","chggaicdeeeihe","aeecbahgdhijdhj","geji","heejedgg","bahdibgfdd","ggaacaedahj","dcfagcjffjj","eiibj","bdcgacca","baigjaf","eagj","bfhd","eghfe","gbeieeeeddcajd","hbabf","aiich","caaebacihj","jbcbhfefiedb","jhhhg","cabbhgbddcibb","gajfefjfchccd","dehccedeghhgb","fceadjbdihchiaefgig","deib","acbcefbdigfj","bce","bjhdidejaaabi","iffei","fjjjd","eejdiacbbjcbehbefd","bjb","dhfcfajbgdidc","dgaifiada","bhjefbjhgje","gacfgifjhhcabiihgieb","gegfcbgfgbd","jgbffaihddahhheebh","djbgcjggjifidcjieca","bajai","ifbbicabfgceaeahde","igbahdcbdbcie","fcideiajgec","gihfedcddhgajc","ehfeihfdeehegjdbdi","cadhjchdh","hhaiiaebb","afidcgjbc","hgbdcgdeeiajijee","geghhe","beh","egfccbbhgbgijg","figeejbcjgedhhfeieci","ejgjfiha","dbb","eaibfhehhha","eeeabjjdigadjcgeaec","aeabagigdadeebg","ccdedheiedefajcg","daiiaaijgdifdgafhai"
        //"a", "" // [[0,1],[1,0]]
    };
    
    vector<vector<int>> r0 = sol.palindromePairs0(words);
    for (auto v: r0) {
        cout << "[" << v[0] << ", " << v[1] << "]\n";
    }
    
    cout << '\n';
    
    vector<vector<int>> r = sol.palindromePairs(words);
    for (auto v: r) {
        cout << "[" << v[0] << ", " << v[1] << "]\n";
    }
    
    return 0;
}
