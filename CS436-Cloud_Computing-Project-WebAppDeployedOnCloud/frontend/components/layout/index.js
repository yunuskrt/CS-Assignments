import React from 'react'
import AppHeader from '@components/layout/header'
const Layout = ({ app }) => {
	return (
		<div>
			<AppHeader />
			<div
				style={{
					padding: '20px',
					display: 'flex',
					justifyContent: 'center',
				}}
			>
				{app}
			</div>
		</div>
	)
}

// articleRoute
// router.post('/', articleController.createArticle)
// router.put('/:id', articleController.updateArticle)
// router.delete('/:id', articleController.deleteArticle)
// router.get('/u/:username', articleController.getArticlesUser)
// router.get('/:id', articleController.getArticle)
// router.get('/:id/like', articleController.likeUnlike)

// commentRoute
// router.post('/', commentController.addComment)
// router.get('/:ArticleId', commentController.getbyPostId)

// userRoute
// router.post('/register', userController.createUser) --> done
// router.get('/u/:username', userController.getUserByUsername) --> done

// router.get('/followings/:username', userController.getFollowings)
// router.get('/followers/:username', userController.getFollowers)

// router.put('/:username/follow', userController.followUser)
// router.put('/:username/unfollow', userController.unfollowUser)
export default Layout
