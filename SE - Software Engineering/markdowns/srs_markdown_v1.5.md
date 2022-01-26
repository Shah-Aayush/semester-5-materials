# Student Helper Portal

**Division:** D

**Batch:** D1

**Group Details:** Vatsal Sakariya (19BCE234), Harshil Sanghvi (19BCE238), Aayush Shah (19BCE245)

## Software Requirements Specification

### 1. Purpose

The main objective of the document is to illustrate the requirements of the Student helper Portal. The document gives us detailed description of both functional and non-functional requirements of the system.

#### 1.1. Scope

Scope of the proposed system is to provide a platform where

- University students can connect with other students
- Students can collaborate with other students’ projects
- Upcoming events showcase
- Student Discussion Forum
- Lecture notes and academics related document sharing

#### 1.2. Overview

Student Helper Portal would be able to provide all in one platform for university students. Students can share their academics related documents along with lecture notes with each other. Professors can share lecture recordings, Examination schedules and can arrange doubt clearing sessions.

There is an Event showcase section, in which all upcoming Tech-Fests, Hackathons and Competitions related information will be available so that events reachability will be more.

Students can connect with other students easily by collaborating in projects, forming coding groups, solving other students doubts, sharing their interview experiences and their preparation and roadmaps for placements. A Student Discussion Forum is a special section made for this purpose.

At last, Student feedback section is present for the students to request a new feature or improvement of the app.

### 2. Overall Description

#### 2.1. Product Perspective

Our proposed portal will help students to connect with other students easily. Our portal will have features like student discussion form, more event accessibility and easy of registration, ease of books exchange and would help in notes sharing

#### 2.2. Product Functionality/Features

The system will have users such as:

- Students
- Faculties
- Administrator

Major functionality of system will include:

- User Authentication based on University
- User Profile
- Events showcase
- Student Discussion Forum
- Post reactions (upvote, downvote and comments)
- Lecture Notes and Recordings
- Project Collaboration which includes chats feature
- Doubt clearing sessions by faculties
- Coding groups
- Student Feedback section
- Academics and Tech Blogs
- Personalized recommendations of blogs, forums, events and profiles

#### 2.3. User Characteristics

The users who will be using this system must have login ID and password. Also the users must have knowledge of the internet. The student who will be using this system must have valid University mail ID.

There will be three different users who will be using this system:

- University Student
- Faculties
- Administrator

#### 2.4. Constraints

The product will be supported by Android and iOS operating system.

- All Android versions android 5 and above.
- All iOS versions iOS 9.0 and above.

#### 2.5. Assumptions and Dependencies

The proposed system needs an internet connection on the client side. It Firebase on the server side.

### 3. Specific Requirements

#### 3.1. Functional Requirements

##### 3.1.1. Student’s Requirements

1. Login

   To login into the system, the following details are required:

   - Email Address – must be a valid concerned university email address.
   - Password – Password not required as we implemented google auth.

2. Create Account

   - The students can register themselves for the student helper portal.
   - For registering, the following information are required:
     - Email address – Email address will be retrieved from google auth.
     - Password – Password is not required as we implemented google auth.
     - Contact Details:
       - Name
       - Mobile
       - Current Academic details
       - Github Id (only for project collaboration optional)

3. Manage Profile

   - The students can update their profile information whenever required.
   - All the fields mentioned above will be updatable except the email address and name.
   - This changed information will be updated to the Firebase database on successful updation.
   - Every year students have to manually update their semester.

4. Search for various categories

   - The students can search for a specific category like projects, notes, assignments, events etc.
   - The students can search for lecture notes and recordings, assignment etc. by typing keywords or by course code and name.

5. Add/Edit project

   - The students can add the details of the project which they wish to commence.
   - Take all the necessary information required for the project i.e. project title, project description, project status (yet to start/ongoing/completed), project deadline (optional), project collaborators etc.
   - Project reactions
   - Project sharing via url in personal chat or any social media platform (through sharable link).
   - Project timeline (versions, improvement, feature addition, etc. )
   - Specify project details and required developers.
   - Students’ projects will have an unique project id and it will be generated automatically.

6. Project Collaboration

   - Students collaborating for a specific project can chat with each other for matters related to the project in a dedicated chat option.
   - Students can send invitations to their colleagues for collaborating on a project.
   - Invitations for collaborating on a project can be sent by selecting specific student. Here specific students can be chose by typing the name of student or their roll number in search box.
   - If a student receives a request for collaborating on a project then he will be made available two options - accept and reject. Depending on the choice of user, they can choose the suitable option thereby giving their consent for the project.

7. Student Discussion Forum

   - A dedicated forum will be provided to the students where they can discuss academics related questions among their peers. This questions will be visible to all the members of the community and anyone can reply to the questions of other.
   - An option will be provided to student where they can provide reactions to the answers of questions asked in forum. The options include upvote, downvote, share and comments. The comments made by students will be under the surveillance of disciplinary team.
   - When searching for an answer to a particular question, in case of multiple answers, students will be provided with a facility to filter the resultant answers on the basis of most upvotes and most recent.
   - When a question is posted by a student in the forum, they will have an option to generate a link directing to that question. This link can be shared to other people via different platforms eg. WhatsApp, Telegram etc.
   - Students can also filter out questions on the basis of a particular subject or a course. This facilitates them by making it easy for them to study for a particular subject or a course.
   - When a student enters into the forum, the landing page will display trending questions and tags. Students can make use of such tags to find out the QnA relevant to their area of interest.

8. Update personal and academic details

   - Students will be given an option to update their semester every six months. On the basis of semester entered by them, they will be able to study the courses concerned to that semester.
   - Students will have an option to update the branch in which they study.
   - Students will have an option to update the mobile number through which they wish to receive future communications.
   - Students will be able to select minors and also be able to add subjects from the pool of electives.

9. Receive notifications on project-collaboration/post-reactions

   - Push notifications will be sent to the logged in devices of the students in the event of:
     - Receiving notifications for project collaboration
     - Reactions on the posts made by them
     - Their interactions in the forum.
   - Push notifications will be having quick action features such as accepting the invitations, giving like to chats and many more.

10. Upcoming events showcase
   
   - Events such as Hackathons, Tech-Fests, Cultural-Fests and Competitions will be shown in this section.
   - Students can register themselves in the interested events through this section.
   - Recommended events will be shown at top based on students' previous participations and their current academics.
   
11. Tech and Academics blogs
   
   - Students can write and post their own writings and thoughts on technical and academics subjects.
   - Blogs will have reactions like upvotes, comments and views.
   - Academics blog can contain lecture notes, roadmaps for various tech skills, Interview experience, etc.

12. Log a complaint/give feedback/feature request
   
   - Students can log a complaint against a fraud or duplicate blog post, Hate speech or symbols, Bullying or harassment, Misleading, Sale of illegal or regulated goods etc.
   - Students can also request a new feature and give feedback about existing features and sections.

13. Request doubt clearing sessions
   
   - Students can request doubt clearing sessions to faculties and upon significant requests.
      - Number of requests upon which the message will be sent to the faculty, can be decided by the respective faculties.
      - Message will be sent to respective faculties and then faculties can approve or reject the request.
      - If faculty approve the request then notification will be sent to all the students who have requested the doubt clearing session.
   
14. Student Profile
   
   - Students' profile will contain following details :
      - Academics details
      - Contact details
      - Posted projects, collabrations and blogs
      - GitHub and LinkedIn profiles
      
15. Materials Exchange Section

   - Students can exchange their Instruments, Lab coats, Books etc. through this section.
   - Students can also request things [HARSHIL]
   - Owner student will be required to upload proper photographs of the things which they are selling along with its price. [HARSHIL]

##### 3.1.2. Faculty’s Requirements

1. Login

2. Create Account

3. Faculty Profile

4. Manage Profile

5. Lecture Recordings

6. Doubt clearing sessions

7. Projects and Research

8. Notifications upon session requests

9. Tech and Academics blogs

10. Log a complaint


##### 3.1.3. Administrator’s Requirements

1. Login

2. Manage Students and Faculties

3. Manage Events

4. Feedback, Complaints and feature requests dashboard

5. Manage posts and academics 

#### 3.2 External Interface Requirements

1. Software Interfaces

   - Database Management System : Firebase
   - Visual Studio Code
   - Technology : Flutter
   
2. Communication Interfaces

   - The proposed system needs internet connections.
   - The HTTP protocol will be used to facilitate communication between client and server.

#### 3.3 Design and Implementation Constraints
   
As there is only one firebase online database implemented in our app, we don't require any synchronization between online and offline databases. [HARSHIL]