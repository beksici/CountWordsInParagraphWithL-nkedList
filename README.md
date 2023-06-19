Kocaeli Üniversitesi


|<p>Bilgisayar Mühendisliği Bölümü </p><p>Programlama Laboratuvarı I</p><p>Bağlı Liste ile Kelime Sayma</p><p>Bünyamin Ekşici</p><p>170201014@kocaeli.edu.tr</p>|
| :-: |


**Problem Tanımı**

`   `Input olarak bize verilen cümleyi kelimelerini ve adet miktarını içinde barındıran bağlı liste yardımı ile saydırmak ve bu oluşturduğumuz listeyi de en büyük adet miktarından en küçüğe doğru sıralayıp output olarak kullanıcıya yansıtmak.

**Yapılan Araştırmalar**

**  Öncelikle problemin veri yapıları bağlı site problemi olduğunu anladım. Bizden dil olarak C dilini kullanmamızı istenmişti. Bende hemen C bilgimi tekrar ettim. Bunu ‘Palme yayınları  Programlamayı C ile Öğreniyorum’ kitabından yaptım. C dili ile ilgili bilgimi tazeledikten sonra sırada veri yapıları bağlı liste konusuna göz atmam gerekti. Bu konuda da Youtube ve tarayıcı yardımı ile yaptım. Ve son olarakta bu listenin sıralanması için gerekli olan Sıralama Algoritma mantığına göz attım. Projenin kodlarını yazarken de karşılaştığım sorunları yine Chrome tarayıcı, Youtube ve kitap yardımı ile çözdüm. Ve bu araştırmalardan yararlanarak problemi çözdüğümü düşünüyorum.

**Tasarım**

Akış şeması:

`   `Akış şeması görseli 2.sayfada yer almaktadır. 

Bu şemada fonsiyonların ve struct yapısının ayrıntılarına girilmemiştir. Fonksiyonlar işlem olarak alınmış olup temel seviyede çizilmiştir. Ayrıntılarına ise genel yapı kısmında değinilecektir.

Yazılım mimarisi:

Yazılım mimarisi görseli 3. Sayfada gösterilmiştir.

**Genel Yapı**

Projemizin genel yapısını anlamak için öncelikle hangi fonksiyonun ne işe yaradığı ve hangi aşamada kullanıldığını göstermemiz gerekiyor.

Öncelikle bize verilecek dosyanın içerisinde Türkçe karakter olma olasılığı olduğu için setLocela() fonksiyonu ile Türkçe karakterleri tanır hale getiriyoruz. Gelelim düğüm yapımıza düğümümüz typedef yapılarak kod okunabilirliği arttırlımıştır. Düğümün içerdiği bilgiler kelime , adet ve tabiki bir sonraki düğümün adresini gösteren pointerdır. Dosyamızı fopen() fonsiyonu yardımı ile açtıktan sonra dosya sonuna kadar bir döngü içinde okuma işlemi yapıyoruz. İlk kelime okunacağı basaEkle() fonksiyonu kullanacağı  için bir koşul ile ilk kelime olduğunu anlıyoruz ve düğüm oluşturmaya başlıyoruz. Hatırlatmak isterim ki bizim 3 tane de şuan için genel değişkenimiz ve boşluğu gösteren 3 düğümümüz var bunlar root(asil düğümümüz için),geciciDugum(adında anlaşılacağı gibi geçici işlemlerde kullanılmak için) ve traverseDugum (gezmek) için kullanıyoruz.

` `Tekrar akışa dönersek kelimeyi okuduk toLower fonsiyonu ile küçük  harfe çevirip bir düğüm oluşturuyoruz. Bunun içinde dugumOlustur() fonksiyonunu kullanıyoruz ve geciciDugume atıyoruz. İlk kelime kontolu yapıldıktan sonra dugumdeAra() fonsiyonu ile traverse düğümümüzü ve oluşan geçici düğümü oluşturduğumuz link listte var mı kontrolu yapılıyor. Eğer varsa  o kelimeden o kelimeyi barındıran düğümün adeti arttırılıyor. Eğer yok ise o düğüm sona ekleniyor. Bunun için ise dugumdeAra fonksiyonu içinde  sonaEkle() fonksiyonunu kullanıyoruz. 

`  `Son olarak listeyi sıralama işlemi yapıyoruz. Bu işlemde listeyiSırala() fonsiyonunu kullanıyoruz. Temelinde bubble sort olan ve arayaEkle() fonksiyonunu da kullanarak yazdığımız bu fonksiyon ile sıralama yapılmış oluyor.

`  `Artık geriye sadece yazdırma işlemi kalıyor bunu da yazdır fonksiyonu olan yazdır() ve listenin boyutu içinde kullanığımız dugumBoyutu() ile yapıyoruz. Yazdırma işlemi bittikten sonra ramda yer kaplamaması için fclose() ile dosyamızı kapatıyoruz.









![C:\Users\evolutıon\Desktop\1609864906335.jpg](img/1609864906335.jpg)

![C:\Users\evolutıon\Desktop\1609864906241.jpg](img/1609864906241.jpg)

**Referanslar**

1. Palme Yayınevi Programlamayı C ile Öğreniyorum Muhammed Y.  Seher Y.

1. <https://www.javatpoint.com/pprogram-to-sort-the-elements-of-the-singly-linked-list>( erişim tarihi: 05.01.2021)


1. Youtube Algoritma Uzmanı kanalı,Bilgisayar Kavramları kanalı https://youtube.com/playlist?list=PLUUSh8du1azZEsdngPxMQGLnatId0V4h9 (erişim tarihi:05.01.2021)



1. <https://ckaynak.com/veri-yapilari/tek-yonlu-bagli-liste> (erişim tarihi:05.01.2021)

1. https://stackoverflow.com/questions/2661766/how-do-i-lowercase-a-string-in-c (erisim tarihi: 26.12.2020)
