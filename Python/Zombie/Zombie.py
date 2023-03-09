import pygame

pygame.init()#تجهيز المكتبة للعمل
screenWIDTH=800
screenHIGHT=400

screen = pygame.display.set_mode((screenWIDTH,screenHIGHT))#إنشاء نافذة العرض وتحديد عرضها وطولها
pygame.display.set_caption("Zombie")#وضع اسم للبرنامج من الأعلى
#عنما نستخدم display يكون التعديل أو الإضافة في الجزء الخارجي
BLACK = (0,0,0)#RGB
WHITE = (255,255,255)

font = pygame.font.Font("freesansbold.ttf", 20)

move_right=[ pygame.image.load("PicsArt_01-28-04.07.53.png"),pygame.image.load("PicsArt_01-28-03.25.56.png"),
             pygame.image.load("PicsArt_01-28-03.48.21.png"),pygame.image.load("PicsArt_01-28-04.07.53.png"),
             pygame.image.load("PicsArt_01-28-03.25.56.png"),pygame.image.load("PicsArt_01-28-12.39.07.png")]

move_right[0]=pygame.transform.scale(move_right[0],(100,100))
move_right[1]=pygame.transform.scale(move_right[1],(100,100))
move_right[2]=pygame.transform.scale(move_right[2],(100,100))
move_right[3]=pygame.transform.scale(move_right[3],(100,100))
move_right[4]=pygame.transform.scale(move_right[4],(100,100))
move_right[5]=pygame.transform.scale(move_right[5],(100,100))

move_left=[ pygame.image.load("1_4.png"),pygame.image.load("2_5.png"), pygame.image.load("3.png"),
            pygame.image.load("1_4.png"),pygame.image.load("2_5.png"),pygame.image.load("6.png")]
move_left[0]=pygame.transform.scale(move_left[0],(100,100))
move_left[1]=pygame.transform.scale(move_left[1],(100,100))
move_left[2]=pygame.transform.scale(move_left[2],(100,100))
move_left[3]=pygame.transform.scale(move_left[3],(100,100))
move_left[4]=pygame.transform.scale(move_left[4],(100,100))
move_left[5]=pygame.transform.scale(move_left[5],(100,100))

bg=pygame.image.load("background.png")
zombie = pygame.image.load("PicsArt_01-28-01.23.02.png")
zombie= pygame.transform.scale(zombie,(65,100))
clock = pygame.time.Clock()
class player():
    def __init__(self,x,y,width,hight):
        self.x=x
        self.y=y
        self.width=width
        self.hight=hight
        self.speed=10
        self.step=10
        self.isjumping=False
        self.left=False
        self.right=False
        self.moves=0
        self.move_bg=0
        self.score=0

    def draw(self,screen):

        if man.x > screenWIDTH  // 2:
            man.move_bg-=man.step
            man.x-=man.step
        if man.move_bg<=-800:
            man.move_bg=0
        screen.blit(bg, (man.move_bg, 0))

        if man.move_bg<0 :
            screen.blit(bg,(800+man.move_bg,0))

        if man.right :
            screen.blit(move_right[man.moves//2],(man.x,man.y))
            man.moves+=1

            if man.moves==12:
                man.moves=0

        elif man.left:
            screen.blit(move_left[man.moves//2],(man.x,man.y))
            man.moves+=1

            if man.moves==12:
                man.moves=0

        else:
            screen.blit(zombie,(man.x,man.y)) #تعليمة الرسم : ترسم شكل لكن لاتظهره على الشاشة وندخل لها على الترتيب : اسم الشاشة التي نرسم عليها و لون الشكل الذي نرسمه و إحداثيات مركز الشكل(وهى النقطة العليا من اليسار) و طوله وعرضه

        screen.blit(text, (650, 20))
        pygame.display.update()  # تحديث المظهر للإظهار الأشياء التي أضفناها أو رسمناها
man=player(50,240,50,50)

while True:

    clock.tick(30)

    text = font.render("score : " + str(man.score), True, WHITE)

    for event in pygame.event.get():#أخذ الزر الذي يكبسه المستخدم
        if event.type == pygame.QUIT :#نوع الزر الذي كبسه المستخدم هو زر الخروج
            quit()#تعليمة الخروج من اللعبة

    keys = pygame.key.get_pressed()#تستقبل الأزرار الفرق أنها تستقبل كبسات طويلة event تستقبل مرة واحدة فقط

    if 450+man.move_bg<=man.x <= 590+man.move_bg and man.y==143.75:
        man.score+=5

    if 450+man.move_bg<= man.x <590+man.move_bg and man.y>=240:
        man.y+=10
        man.step=0
        isjumping=False
        if man.y==400:
            quit()

    if keys[pygame.K_RIGHT] and man.x + man.width + man.step <= screenWIDTH :# الشرط الثاني لإضافة الحدود و ال-50 لأن عرض المربع +width والمركز يقع في الزاوية العليا اليسارية:
        man.x += man.step
        man.right=True
        man.left=False

    elif keys[pygame.K_LEFT] and man.x - man.step >= 0 :
        man.x -= man.step
        man.left=True
        man.right=False

    else:
        man.right=False
        man.left=False
        man.moves=0

    if not man.isjumping :

        if keys[pygame.K_SPACE]:
            man.isjumping = True

    else :#القفز

        if man.speed >= -10:

            neg = 1

            if man.speed <= 0:

                neg = -1
            man.y-=(man.speed**2)*0.25*neg
            man.speed-=1

        else:

            man.speed =10
            man.isjumping = False

    man.draw(screen)
