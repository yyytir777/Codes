-- 1번 쿼리 : 가게 이름, 완료 여부
select mm.id, m.name, mm.completed_or_not 
from misson m, my_mission mm
where m.id = mm.mission_id;


-- 2번 쿼리 : 닉네임, 별점, 내용
select m.id, m.nickname, r.grade, r.content
from review r, visited_restaurant vr, member m
where m.id = vr.member_id and vr.id = r.visitied_restaurant_id
limit 3 offset 3;


-- 3번 쿼리 : 현재 지역, 가능 미션, 페이징 포함
select l.name, m.name, m.content
from location l, restaurant r, mission m, my_mission mm
where mm.mission_id = m.id and m.restaurant_id = r.id and r.location_id = l.id and mm.completed_or_not = '0';

-- 4번 쿼리 : 마이페이지 -> 닉네임, 이메일, 휴대폰번호, 포인트
select nickname, email, phone_number, point
from member m
where id = 'test';