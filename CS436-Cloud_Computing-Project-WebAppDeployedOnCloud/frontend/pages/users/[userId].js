import React, { useEffect, useState } from 'react'
import { useRouter } from 'next/router'
import { Button, ButtonGroup } from 'react-bootstrap'

const UserPage = () => {
	const router = useRouter()
	const { userId } = router.query
	const [data, setData] = useState(null)

	useEffect(() => {
		if (userId) {
			let userFound = false
			let username = ''
			let followers = []
			let followings = []
			const fetchData = async () => {
				try {
					const response = await fetch(
						`https://api-nodejs-y7qorp3gha-ey.a.run.app/api/user/u/${userId}`
					)
					const user = await response.json()
					if (user.status == 'success') {
						userFound = true
						username = user.user
					}
				} catch (error) {
					console.error('Error fetching data:', error)
				}

				if (userFound) {
					try {
						const followersRes = await fetch(
							`https://api-nodejs-y7qorp3gha-ey.a.run.app/api/user/followers/${username}`
						)
						const followerJson = await followersRes.json()
						followers = followerJson.data.followings

						const followingsRes = await fetch(
							`https://api-nodejs-y7qorp3gha-ey.a.run.app/api/user/followings/${username}`
						)
						const followingJson = await followingsRes.json()
						followings = followingJson.followings

						setData({
							status: 'success',
							user: username,
							followers: followers,
							followings: followings,
						})
					} catch (error) {
						console.error('Error fetching data:', error)
					}
				}
			}
			fetchData()
		}
	}, [userId])

	if (!userId) {
		return <div>Loading...</div>
	} else if (data == null) {
		return <div>Loading...</div>
	} else if (data.status != 'success') {
		return <div>User not found</div>
	}

	return (
		<div
			style={{
				width: '100%',
				display: 'flex',
				flexDirection: 'column',
			}}
		>
			<div>
				{!userId ? (
					<div>Loading...</div>
				) : data == null ? (
					<div>Loading...</div>
				) : data.status != 'success' ? (
					<div>User not found</div>
				) : (
					<div style={{ width: '100%' }}>
						<div
							style={{
								display: 'flex',
								justifyContent: 'center',
								alignItems: 'center',
								fontSize: '30px',
								fontWeight: 'bold',
							}}
						>
							Username: {data.user}
						</div>
						<div style={{ display: 'flex', justifyContent: 'center' }}>
							<ButtonGroup aria-label='Basic example'>
								<Button variant='primary'>Follow</Button>
								<Button variant='secondary'>UnFollow</Button>
							</ButtonGroup>
						</div>

						<div style={{ fontWeight: 'bold', fontSize: '20px' }}>
							Followers:
						</div>
					</div>
				)}
			</div>
		</div>
	)
}

export default UserPage
